//
// Copyright 2022 Signal Messenger, LLC
// SPDX-License-Identifier: AGPL-3.0-only
//

/* eslint-disable no-console */

const https = require('https');
const { HttpsProxyAgent } = require('https-proxy-agent');
const fs = require('fs');
const path = require('path');
const crypto = require('crypto');
const tar = require('tar');
const { Transform } = require('stream');
const { pipeline } = require('stream/promises');

const VERSION = process.env.npm_package_version;
const URL = process.env.npm_package_config_prebuildUrl.replace(
  '${npm_package_version}', // eslint-disable-line no-template-curly-in-string
  VERSION
);
const HASH = process.env.npm_package_config_prebuildChecksum;

const tmpFile = path.join(__dirname, 'unverified-prebuild.tmp');
const finalFile = path.join(__dirname, 'prebuild.tar.gz');

async function main() {
  return;
  if (!HASH) {
    console.log('(no checksum provided; assuming local build)');
    process.exit(0);
  }

  await downloadIfNeeded();
  console.log('extracting...');
  await tar.extract({ file: finalFile, onwarn: process.emitWarning });
}

async function downloadIfNeeded() {
  if (fs.statSync(finalFile, { throwIfNoEntry: false })) {
    const hash = crypto.createHash('sha256');
    await pipeline(fs.createReadStream(finalFile), hash);
    if (hash.digest('hex') === HASH) {
      console.log('local build artifact is up-to-date');
      return;
    }

    console.log('local build artifact is outdated');
  }
  await download();
}

function download() {
  console.log(`downloading ${URL}`);
  return new Promise((resolve, reject) => {
    let options = {};
    if (process.env.HTTPS_PROXY != undefined) {
      options.agent = new HttpsProxyAgent(process.env.HTTPS_PROXY);
    }
    https.get(URL, options, async res => {
      try {
        const out = fs.createWriteStream(tmpFile);

        const hash = crypto.createHash('sha256');

        const t = new Transform({
          transform(chunk, encoding, callback) {
            hash.write(chunk, encoding);
            callback(null, chunk);
          },
        });

        await pipeline(res, t, out);

        const actualDigest = hash.digest('hex');
        if (actualDigest !== HASH) {
          fs.unlinkSync(tmpFile);
          throw new Error(
            `Digest mismatch. Expected ${HASH} got ${actualDigest}`
          );
        }

        fs.renameSync(tmpFile, finalFile);
        resolve();
      } catch (error) {
        reject(error);
      }
    });
  });
}

main();
