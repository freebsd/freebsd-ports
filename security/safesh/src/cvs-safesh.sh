#!/bin/sh
if [ "$2" = "-l" ]; then
	exec safesh $3@$1 -- "$@"
else
	exec safesh $1 -- "$@"
fi
