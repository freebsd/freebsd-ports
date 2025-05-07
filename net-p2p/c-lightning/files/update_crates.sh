#!/usr/bin/env bash

set -e

# cargo install cargo-lock --features cli
# make clean extract

cargo-lock --file "$(make -V WRKSRC)/Cargo.lock" \
    | grep -vE "(cln-rpc|cln-grpc|clnrest|grpc-plugin|rest-plugin)" \
    | sed -E 's/^- ([^ ]+) (.+)$/CARGO_CRATES+=\t\1-\2/g' > Makefile.crates
