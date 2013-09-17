# Created by: Vladimir Ermakov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	netxms
PORTVERSION=	1.0.13
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Network monitoring system

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

PORTSCOUT=	limit:^1\.0\.[0-9]* 	# 1.1.X branch is Development Branch

OPTIONS_DEFINE=	SERVER CLIENT AGENT NXHTTPD MYSQL PGSQL SQLITE ODBC
OPTIONS_DEFAULT=	CLIENT AGENT
SERVER_DESC=	Install NetXMS server & agent
CLIENT_DESC=	Install NetXMS client
AGENT_DESC=	Install NetXMS agent
NXHTTPD_DESC=	Install web-interface

BROKEN=		Does not fetch

NO_PACKAGE=	yes

USE_OPENSSL=	yes
USES=		iconv gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NETXMS_OWN=	netxms
NETXMS_GRP=	netxms

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-install	pkg-deinstall

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT} || ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MNXHTTPD}
PLIST_SUB+=	NXCPTEST=""
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
.else
PLIST_SUB+=	NXCPTEST="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MNXHTTPD}
PLIST_SUB+=	NXMAP=""
.else
PLIST_SUB+=	NXMAP="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MNXHTTPD}
PLIST_SUB+=	NXCL=""
.else
PLIST_SUB+=	NXCL="@comment "
.endif

.if ! ${PORT_OPTIONS:MSERVER}
PLIST_SUB+=	SERVER="@comment "
.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MSQLITE} || ${PORT_OPTIONS:MODBC}
IGNORE=	is useless database support without a SERVER. Please (re)run 'make config' and choose SERVER with database
.endif
.else
CONFIGURE_ARGS+=	--with-server
PLIST_SUB+=	SERVER=""
.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MSQLITE} && ! ${PORT_OPTIONS:MODBC}
IGNORE=	is useless without a database. Please (re)run 'make config' and choose database support
.else
USE_RC_SUBR+=	netxmsd
.if ${PORT_OPTIONS:MAGENT}
PLIST_SUB+=	AGENT="@comment "
.else
USE_RC_SUBR+=	nxagentd
.endif
.endif
.endif

.if ${PORT_OPTIONS:MCLIENT}
CONFIGURE_ARGS+=	--with-client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MAGENT}
USE_RC_SUBR+=	nxagentd
CONFIGURE_ARGS+=	--with-agent
PLIST_SUB+=	AGENT=""
.else
PLIST_SUB+=	AGENT="@comment "
.endif

.if ${PORT_OPTIONS:MNXHTTPD}
USE_RC_SUBR+=	nxhttpd
CONFIGURE_ARGS+=	--with-nxhttpd
PLIST_SUB+=	NXHTTPD=""
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
.else
PLIST_SUB+=	NXHTTPD="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=	--with-mysql
PLIST_SUB+=	MYSQL=""
USE_MYSQL=	yes
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
CONFIGURE_ARGS+=	--with-pgsql
PLIST_SUB+=	PGSQL=""
USE_PGSQL=	yes
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
CONFIGURE_ARGS+=	--with-sqlite
PLIST_SUB+=	SQLITE=""
USE_SQLITE=	yes
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--with-odbc
PLIST_SUB+=	ODBC=""
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
.else
PLIST_SUB+=	ODBC="@comment "
.endif

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	                ${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
.if ${PORT_OPTIONS:MSERVER}
.if !exists(${PREFIX}/etc/netxmsd.conf-dist)
	${INSTALL_DATA} ${WRKSRC}/contrib/netxmsd.conf-dist ${PREFIX}/etc
	${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/netxmsd.conf-dist
.endif
.endif
.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT}
.if !exists(${PREFIX}/etc/nxagentd.conf-dist)
	${INSTALL_DATA} ${WRKSRC}/contrib/nxagentd.conf-dist ${PREFIX}/etc
	${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/nxagentd.conf-dist
.endif
.endif
.if ${PORT_OPTIONS:MNXHTTPD}
.if !exists(${PREFIX}/etc/nxhttpd.conf-dist)
	${INSTALL_DATA} ${WRKSRC}/contrib/nxhttpd.conf-dist ${PREFIX}/etc
	${CHOWN} ${NETXMS_OWN}:${NETXMS_GRP} ${PREFIX}/etc/nxhttpd.conf-dist
.endif
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.post.mk>
