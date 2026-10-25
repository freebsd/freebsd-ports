// follow-dir-links.cjs - let directory completion see symlinked directories.
//
// Not a Bun API, and so kept out of bun-polyfill.cjs: this works around a bug
// in claude-code itself, present on every platform. Its path completers --
// the one behind /cd and /add-dir, and the general one in the prompt -- take
// Dirent.isDirectory() for "is a directory one can enter". A Dirent describes
// the entry, not what it points to (as lstat(2) would), so a symbolic link to
// a directory is not one: /cd leaves it out altogether, and the prompt offers
// it as a plain file. With /usr/ports a link, "/cd /usr/p<TAB>" found nothing.
//
// scripts/post-extract feeds the readdir() result of both completers through
// this function. Remove the two together once upstream follows links itself.
'use strict';

const path = require('path');

// Hand back the entries of dir, with every symbolic link that resolves to a
// directory answering isDirectory() as the directory it leads to. fsw is the
// bundle's own filesystem wrapper, which its completers read the listing
// through; the link is resolved through it too. A dangling link, or one that
// cannot be followed, stays what readdir() said it was.
module.exports = async function (dirents, dir, fsw) {
	return (Promise.all(dirents.map(async (d) => {
		if (!d.isSymbolicLink())
			return (d);

		try {
			if (!(await fsw.stat(path.join(dir, d.name))).isDirectory())
				return (d);
		} catch {
			return (d);
		}

		return (Object.create(d, {
			isDirectory: { value: () => true },
		}));
	})));
};
