# Ports collection makefile for:        netxms
# Date created:         Jul 9 2007
# Whom:                 Vladimir Ermakov <samflanker@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netxms
PORTVERSION=	0.2.24
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NetXMS - network monitoring system

BROKEN=	does not compile with gcc 4.2

NO_PACKAGE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=	SERVER "Install NetXMS server & agent" off \
		CLIENT "Install NetXMS client" on \
		AGENT "Install NetXMS agent" on \
		NXHTTPD "Install web-interface" off \
		MYSQL "Enable MySQL support" off \
		PGSQL "Enable PostgreSQL support" off \
		SQLITE "Enable SQLITE support" off \
		ODBC "Enable ODBC support" off

NETXMS_OWN=	netxms
NETXMS_GRP=	netxms

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-install	pkg-deinstall

.if defined(WITH_SERVER) || defined(WITH_AGENT) || defined(WITH_CLIENT) || defined(WITH_NXHTTPD)
PLIST_SUB+=	NXCPTEST=""
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
.else
PLIST_SUB+=	NXCPTEST="@comment "
.endif

.if defined(WITH_SERVER) || defined(WITH_CLIENT) || defined(WITH_NXHTTPD)
PLIST_SUB+=	NXMAP=""
.else
PLIST_SUB+=	NXMAP="@comment "
.endif

.if defined(WITH_CLIENT) || defined(WITH_NXHTTPD)
PLIST_SUB+=	NXCL=""
.else
PLIST_SUB+=	NXCL="@comment "
.endif

.if !defined(WITH_SERVER)
PLIST_SUB+=	SERVER="@comment "
.if defined(WITH_MYSQL) || !defined(WITHOUT_PGSQL) || !defined(WITHOUT_SQLITE) || !defined(WITHOUT_ODBC)
IGNORE=	is useless database support without a SERVER. Please (re)run 'make config' and choose SERVER with database
.endif
.else
CONFIGURE_ARGS+=	--with-server
PLIST_SUB+=	SERVER=""
.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL) && !defined(WITH_SQLITE) && !defined(WITH_ODBC)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose database support
.else
USE_RC_SUBR+=	netxmsd
.if defined(WITH_AGENT)
PLIST_SUB+=	AGENT="@comment "
.else
USE_RC_SUBR+=	nxagentd
.endif
.endif
.endif

.if defined(WITH_CLIENT)
CONFIGURE_ARGS+=	--with-client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_AGENT)
USE_RC_SUBR+=	nxagentd
CONFIGURE_ARGS+=	--with-agent
PLIST_SUB+=	AGENT=""
.else
PLIST_SUB+=	AGENT="@comment "
.endif

.if defined(WITH_NXHTTPD)
USE_RC_SUBR+=	nxhttpd
CONFIGURE_ARGS+=	--with-nxhttpd
PLIST_SUB+=	NXHTTPD=""
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
USE_PERL5=	yes
.else
PLIST_SUB+=	NXHTTPD="@comment "
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	yes
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	yes
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE=""
USE_SQLITE=	yes
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=	--with-odbc
PLIST_SUB+=	ODBC=""
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
.else
PLIST_SUB+=	ODBC="@comment "
.endif

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	                ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.if defined(WITH_SERVER)
	@if [ ! -f ${PREFIX}/etc/netxmsd.conf-dist ]; then \
	        ${CP} -p ${WRKSRC}/contrib/netxmsd.conf-dist ${PREFIX}/etc/netxmsd.conf-dist ; \
	fi
.endif
.if defined(WITH_SERVER) || !defined(WITHOUT_AGENT)
	@if [ ! -f ${PREFIX}/etc/nxagentd.conf-dist ]; then \
	        ${CP} -p ${WRKSRC}/contrib/nxagentd.conf-dist ${PREFIX}/etc/nxagentd.conf-dist ; \
	fi
.endif
.if defined(WITH_NXHTTPD)
	@if [ ! -f ${PREFIX}/etc/nxhttpd.conf-dist ]; then \
	        ${CP} -p ${WRKSRC}/contrib/nxhttpd.conf-dist ${PREFIX}/etc/nxhttpd.conf-dist ; \
	fi
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	                ${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
.if defined(WITH_SERVER)
			${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/netxmsd.conf-dist
			${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/nxagentd.conf-dist
.endif
.if defined(WITH_AGENT)
			${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/nxagentd.conf-dist
.endif
.if defined(WITH_NXHTTPD)
			${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/nxhttpd.conf-dist
.endif

post-deinstall:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	                ${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
