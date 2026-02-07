#!/bin/sh

cd %%PATH%%
exec %%JAVA_CMD%% -jar -Xmx256m %%DIRBUSTER%% "$@"
