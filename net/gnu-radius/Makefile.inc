CONFIGURE_ARGS+= --with-client
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client:install
CONFIGURE_ARGS+= --with-mysql
CONFIGURE_ARGS+= --enable-snmp
BUILD_DEPENDS+= guile:${PORTSDIR}/lang/guile
