#!/bin/sh
#
# install.sh v0.1
#
# Install script which reads files from the plist and copies them to the appropriate
# location and makes directories for them if necessary

%%MKDIR%% %%INSTALLDIR%%

# Install the required files
for file in `cat pkg-plist | grep -v @ | grep ISMAILDIR | sed 's,%%[A-Z]*%%,,g'`; do
        dir=`echo "${file}" | sed 's,/[^/]*$,/,g'`
       if [ -d %%WRKSRC%%/ismail/${dir} ]; then
                %%MKDIR%% %%INSTALLDIR%%/${dir}
       fi
       %%INSTALL_SCRIPT%%  %%WRKSRC%%/ismail/${file} %%INSTALLDIR%%/${file}
done
