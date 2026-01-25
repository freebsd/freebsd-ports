#!/bin/sh


STRICT="set -euo pipefail"
$STRICT


# args
: "${1?Usage: $0 <version>}"

VERSION="$1"

# consts
GH_PROJECT="ollama"
GH_ACCOUNT_ORIG="ollama"
GH_ACCOUNT_FORK="yurivict"


echo "updating $GH_PROJECT to version $VERSION"

# remove old dirs
rm -rf $GH_ACCOUNT_ORIG-$GH_PROJECT.repo $GH_ACCOUNT_FORK-$GH_PROJECT.repo

# clone repos
git clone https://github.com/$GH_ACCOUNT_ORIG/$GH_PROJECT.git $GH_ACCOUNT_ORIG-$GH_PROJECT.repo
git clone https://github.com/$GH_ACCOUNT_FORK/$GH_PROJECT.git $GH_ACCOUNT_FORK-$GH_PROJECT.repo

# checkout version
cd $GH_ACCOUNT_ORIG-$GH_PROJECT.repo
git checkout v$VERSION

cd ../$GH_ACCOUNT_FORK-$GH_PROJECT.repo
rm -rf *
cp -r \
	../$GH_ACCOUNT_ORIG-$GH_PROJECT.repo/* \
	../$GH_ACCOUNT_ORIG-$GH_PROJECT.repo/.gitattributes \
	../$GH_ACCOUNT_ORIG-$GH_PROJECT.repo/.github \
	../$GH_ACCOUNT_ORIG-$GH_PROJECT.repo/.gitignore \
	../$GH_ACCOUNT_ORIG-$GH_PROJECT.repo/.golangci.yaml \
	.

# apply freebsd compatibility patch
(patch-no-backup-1 < ../files/freebsd-compatibility.patch) || { echo "error: failed to apply freebsd compatibility patch"; exit 1; }

# it should be buildable at this point

#update $GH_ACCOUNT_ORIG/$GH_PROJECT -> $GH_ACCOUNT_FORK/$GH_PROJECT # this is done in the port

# commit and tag
echo "==> committing version v$VERSION"
git add * .gitattributes .github .gitignore .golangci.yaml
git commit * .gitattributes .github .gitignore .golangci.yaml -m "Update to version v$VERSION + freebsd patches"
echo "==> tagging version v$VERSION"
git tag -a v$VERSION -m "Release version v$VERSION + freebsd patches"

# push changes
git push origin
git push --tags

# make GoLang proxy
echo "==> submitting the new version $VERSION to GoLang proxy"
GOPROXY=proxy.golang.org go124 list -m github.com/$GH_ACCOUNT_FORK/ollama@v$VERSION

# final message
echo "success: done updating the $GH_ACCOUNT_FORK/$GH_PROJECT to version $VERSION"
