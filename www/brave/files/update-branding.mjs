// Copyright (c) 2026 The FreeBSD Ports Project
// SPDX-License-Identifier: BSD-2-Clause
//
// Runs brave-core's own branding step.  Brave's build driver does this before
// it starts ninja: it copies brave-core's strings, translations, themes,
// icons and branded grd files over the matching files in the Chromium tree.
// A port that drives ninja itself never gets that step, and the build then
// fails the first time grit is asked for a locale Brave adds and Chromium's
// grd does not list.
//
// Takes the path of src/brave/build/commands.  Everything below it is imported
// by absolute path, so the bare imports in those modules ('fs-extra' and the
// rest) still resolve through src/brave/node_modules.

const commandsDir = process.argv[2]
if (!commandsDir) {
  console.error('usage: update-branding.mjs <path to src/brave/build/commands>')
  process.exit(1)
}

const config = (await import(`${commandsDir}/lib/config.ts`)).default
const branding = (await import(`${commandsDir}/lib/branding.js`)).default

// The driver sets these from its command line.  Without a channel the config
// defaults to "development", whose BRANDING file names the browser "Brave
// Browser Development"; the port builds the release channel, which is what
// brave_channel="" in the gn args says as well.  isBraveReleaseBuild only
// decides which of @brave/leo's logo variants is copied over the Chromium one.
config.channel = ''
config.isBraveReleaseBuild = () => true

branding.update()
