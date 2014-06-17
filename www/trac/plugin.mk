# needed to avoid polluting /root with .subversion/ leftovers,
# which will cause package builders to complain on staging.
#
# www/trac issues some svn command on installing certain plugins,
# if it was built with the SVN option enabled
MAKE_ENV+=	HOME=/dev/null
