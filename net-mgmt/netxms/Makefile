# Created by: Vladimir Ermakov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	netxms
PORTVERSION=	1.2.14
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/ \
		http://www.netxms.org/download/archive/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Network monitoring system

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	SERVER CLIENT AGENT
OPTIONS_DEFAULT=	CLIENT AGENT
SERVER_ENABLED_MODULES=	MYSQL
SERVER_DISABLED_MODULES=	PGSQL SQLITE ODBC
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	${SERVER_ENABLED_MODULES} ${SERVER_DISABLED_MODULES}
SERVER_DESC=	Install NetXMS server & agent
CLIENT_DESC=	Install NetXMS client
AGENT_DESC=	Install NetXMS agent

NO_PACKAGE=	yes

USE_OPENSSL=	yes
USES=		gmake iconv libtool perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		netxms
GROUPS=		netxms

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT} || ${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	NXCPTEST=""
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2
.else
PLIST_SUB+=	NXCPTEST="@comment "
.endif

.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	NXMAP=""
.else
PLIST_SUB+=	NXMAP="@comment "
.endif

.if ! ${PORT_OPTIONS:MSERVER}
PLIST_SUB+=	SERVER="@comment "
.else
CONFIGURE_ARGS+=	--with-server
PLIST_SUB+=	SERVER=""
USE_RC_SUBR+=	netxmsd
.if ${PORT_OPTIONS:MAGENT}
PLIST_SUB+=	AGENT="@comment "
.else
USE_RC_SUBR+=	nxagentd
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
LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
.else
PLIST_SUB+=	ODBC="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MSERVER}
.if !exists(${STAGEDIR}${PREFIX}/etc/netxmsd.conf-dist)
	${CP} ${WRKSRC}/contrib/netxmsd.conf-dist ${STAGEDIR}${PREFIX}/etc/
.endif
.endif
.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT}
.if !exists(${STAGEDIR}${PREFIX}/etc/nxagentd.conf-dist)
	${CP} ${WRKSRC}/contrib/nxagentd.conf-dist ${STAGEDIR}${PREFIX}/etc/
.endif
.endif

.include <bsd.port.mk>
