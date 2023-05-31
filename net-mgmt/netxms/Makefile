PORTNAME=	netxms
PORTVERSION=	3.4.313
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.netxms.org/download/releases/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Network monitoring system
WWW=		https://www.netxms.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BROKEN_FreeBSD_13=	error: conflicting types for 'qsort_s'
BROKEN_FreeBSD_14=	error: conflicting types for 'qsort_s'

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjansson.so:devel/jansson \
		libpcre.so:devel/pcre \
		libtre.so:textproc/libtre \
		libmosquitto.so:net/mosquitto

USES=		gmake iconv libtool localbase perl5 ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

LDFLAGS+=	-ljansson

USERS=		netxms
GROUPS=		netxms

PLIST_SUB=	SONUM=${SONUM}

OPTIONS_DEFINE=	SERVER CLIENT AGENT SSH
OPTIONS_DEFAULT=	CLIENT AGENT SSH
OPTIONS_SINGLE=	SERVER
OPTIONS_SINGLE_SERVER=	MYSQL PGSQL ODBC
OPTIONS_SUB=	yes

AGENT_DESC=	Install NetXMS agent
CLIENT_DESC=	Install NetXMS client
SERVER_DESC=	Install NetXMS server & agent

AGENT_CONFIGURE_ON=	--with-agent
CLIENT_CONFIGURE_ON=	--with-client
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_ON=	--with-odbc
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql
SERVER_CONFIGURE_ON=	--with-server
SSH_LIB_DEPENDS=	libssh.so:security/libssh
SSH_CONFIGURE_OFF=	--disable-ssh

SONUM=	34

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
