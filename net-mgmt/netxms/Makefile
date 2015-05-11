# Created by: Vladimir Ermakov <samflanker@gmail.com>
# $FreeBSD$

PORTNAME=	netxms
PORTVERSION=	1.2.16
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/ \
		http://www.netxms.org/download/archive/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Network monitoring system

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BROKEN=		Fails to package
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-05-26

OPTIONS_DEFINE=	SERVER CLIENT AGENT
OPTIONS_DEFAULT=	CLIENT AGENT
SERVER_ENABLED_MODULES=	MYSQL
SERVER_DISABLED_MODULES=	PGSQL SQLITE ODBC
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	${SERVER_ENABLED_MODULES} ${SERVER_DISABLED_MODULES}
SERVER_DESC=	Install NetXMS server & agent
CLIENT_DESC=	Install NetXMS client
AGENT_DESC=	Install NetXMS agent

USE_OPENSSL=	yes
USES=		gmake iconv libtool perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--with-internal-libjansson \
		--with-internal-libtre
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		netxms
GROUPS=		netxms

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

post-install:
.if ${PORT_OPTIONS:MSERVER}
.if !exists(${STAGEDIR}${PREFIX}/etc/netxmsd.conf.sample)
	${CP} ${WRKSRC}/contrib/netxmsd.conf-dist ${STAGEDIR}${PREFIX}/etc/netxmsd.conf.sample
.endif
.endif
.if ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MAGENT}
.if !exists(${STAGEDIR}${PREFIX}/etc/nxagentd.conf.sample)
	${CP} ${WRKSRC}/contrib/nxagentd.conf-dist ${STAGEDIR}${PREFIX}/etc/nxagentd.conf.sample
.endif
.endif

.include <bsd.port.mk>
