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
GO_CMD=$(make -V GO_CMD)

# check if GO_CMD is set and is a valid command
if [ -z "$GO_CMD" ]; then
	echo "error: GO_CMD is not set"
	exit 1
fi
if ! command -v "$GO_CMD" >/dev/null 2>&1; then
	echo "error: GO_CMD '$GO_CMD' is not a valid command"
	exit 1
fi

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

# change import path to the fork
grep -rl ollama/ollama | xargs sed -i '' -e 's|ollama/ollama|yurivict/ollama|g'

# it should be buildable at this point

#update $GH_ACCOUNT_ORIG/$GH_PROJECT -> $GH_ACCOUNT_FORK/$GH_PROJECT # this is done in the port

# commit and tag
echo "==> committing version v$VERSION"
git add * .gitattributes .github .gitignore .golangci.yaml
git commit . -m "Update to version v$VERSION + freebsd patches"
echo "==> tagging version v$VERSION"
git tag -a v$VERSION -m "Release version v$VERSION + freebsd patches"

# push changes
git push origin
git push --tags

# make GoLang proxy to ingest the new version
echo "==> submitting the new version $VERSION to the GoLang proxy"
GOPROXY=proxy.golang.org $GO_CMD list -m github.com/$GH_ACCOUNT_FORK/ollama@v$VERSION

# final message
echo "success: done updating the $GH_ACCOUNT_FORK/$GH_PROJECT to version $VERSION"
