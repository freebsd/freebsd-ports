# Ports collection makefile for:        netxms
# Date created:         Jul 9 2007
# Whom:                 Vladimir Ermakov <samflanker@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	netxms
PORTVERSION=	0.2.18.2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/

MAINTAINER=	samflanker@gmail.com
COMMENT=	NetXMS - network monitoring system

NO_PACKAGE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

USE_GCC=	3.4
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-L${OPENSSLLIB} -lcrypto -lssl

OPTIONS=	SERVER "Install NetXMS server & agent" off\
		CLIENT "Install NetXMS client" off \
		AGENT "Install NetXMS agent" off \
		NXHTTPD "Install web-interface" off \
		MYSQL "Enable MySQL support" off \
		PGSQL "Enable PostgreSQL support" off

NETXMS_OWN=	netxms
NETXMS_GRP=	netxms

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-install	pkg-deinstall

.if !defined(WITH_SERVER)
.if defined(WITH_MYSQL) || !defined(WITHOUT_PGSQL)
IGNORE=	is useless database support without a SERVER. Please (re)run 'make config' and choose SERVER with database
.endif
.endif

.if defined(WITH_SERVER)
.if defined(WITHOUT_MYSQL) && !defined(WITH_PGSQL)
IGNORE=	is useless without a database. Please (re)run 'make config' and choose one of PGSQL and MYSQL
.endif
USE_RC_SUBR+=	netxmsd	nxagentd
CONFIGURE_ARGS+=	--with-server
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "	AGENT="@comment "
.endif

.if defined(WITH_CLIENT)
CONFIGURE_ARGS+=	--with-client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_AGENT)
.if defined(WITH_SERVER)
IGNORE=	is useles AGENT or SERVER. Please (re)run 'make config' and choose one of AGENT and SERVER (server already include agent)
.endif
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
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
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
