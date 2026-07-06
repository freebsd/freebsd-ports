PORTNAME=	netxms
DISTVERSION=	6.1.4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.netxms.org/download/releases/${DISTVERSION:R}/

MAINTAINER=	dnpowers@me.com
COMMENT=	Network monitoring system
WWW=		https://www.netxms.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjansson.so:devel/jansson \
		libmosquitto.so:net/mosquitto \
		libpcre2-8.so:devel/pcre2 \
		libtre.so:textproc/libtre

USES=		gmake iconv libedit libtool localbase perl5 shebangfix sqlite \
		ssl
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.sh *asan*

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

LDFLAGS+=	-ljansson

USERS=		netxms
GROUPS=		netxms

PLIST_SUB=	SONUM=${SONUM}

OPTIONS_DEFINE=		AGENT CLIENT SERVER SSH
OPTIONS_DEFAULT=	AGENT CLIENT SSH
OPTIONS_MULTI=		SERVER
OPTIONS_MULTI_SERVER=	MARIADB MYSQL ODBC PGSQL
OPTIONS_SUB=		yes

AGENT_DESC=	Install NetXMS agent
CLIENT_DESC=	Install NetXMS client
MARIADB_DESC=	MariaDB Database Support
SERVER_DESC=	Install NetXMS server & agent

AGENT_CONFIGURE_ON=	--with-agent
CLIENT_CONFIGURE_ON=	--with-client
MARIADB_PREVENTS=	MYSQL
MARIADB_USES=		mysql:118m
MARIADB_CONFIGURE_ON=	--with-mariadb
MARIADB_CFLAGS=		-I${LOCALBASE}/include/mysql
MARIADB_LDFLAGS=	-L${LOCALBASE}/lib/mysql
MYSQL_PREVENTS=		MARIADB
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_ON=	--with-odbc
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql
SERVER_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
SERVER_CONFIGURE_ON=	--with-server
SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_OFF=	--disable-ssh

SONUM=		61

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	NXMAP=""
.else
PLIST_SUB+=	NXMAP="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT}
PLIST_SUB+=	NXCP=""
.else
PLIST_SUB+=	NXCP="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER}
USE_RC_SUBR+=	netxmsd
.if !${PORT_OPTIONS:MAGENT}
USE_RC_SUBR+=	nxagentd
.endif
.endif

.if ${PORT_OPTIONS:MAGENT}
USE_RC_SUBR+=	nxagentd
.endif

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT}
.if !exists(${STAGEDIR}${PREFIX}/etc/nxagentd.conf.sample)
	${CP} ${WRKSRC}/contrib/nxagentd.conf-dist ${STAGEDIR}${PREFIX}/etc/nxagentd.conf.sample
.endif
.endif

post-install-SERVER-on:
.if !exists(${STAGEDIR}${PREFIX}/etc/netxmsd.conf.sample)
	${CP} ${WRKSRC}/contrib/netxmsd.conf-dist ${STAGEDIR}${PREFIX}/etc/netxmsd.conf.sample
.endif

.include <bsd.port.mk>
