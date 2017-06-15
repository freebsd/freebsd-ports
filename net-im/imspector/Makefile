# Created by: Ilja Dejs <ilja.dejs@gmail.com>
# $FreeBSD$

PORTNAME=	imspector
PORTVERSION=	20111108
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://tsatsenko.ru/ports/distfiles/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	IM transparent proxy with monitoring, blocking, and content-filtering

LICENSE=	GPLv2

CFLAGS+=	-fPIC -I ${LOCALBASE}/include -DHAVE_SSL
USES=		gmake iconv ssl
USE_LDCONFIG=	${LOCALBASE}/lib/imspector

CONFIG_FILES=	imspector.conf badwords.txt acl.txt

USE_RC_SUBR=	${PORTNAME}

MAKE_ENV+=	ETCDIR=${ETCDIR} \
		SSL_DIR=${OPENSSLBASE}

OPTIONS_DEFINE=	IPFW PLUGINS
OPTIONS_DEFAULT=IPFW
OPTIONS_SUB=	yes

IPFW_DESC=	Add IPFW support
PLUGINS_DESC=	Build plugins

IPFW_CFLAGS=	-DIPFW_TRANSPARENT=1
PLUGINS_USE=	MYSQL=yes
PLUGINS_USES=	pgsql sqlite

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/imspector.conf \
		${WRKSRC}/main.cpp
	@${REINPLACE_CMD} -e 's,= SSLv23_method(),= (SSL_METHOD *) SSLv23_method(),g' \
		${WRKSRC}/sslstate.cpp
	@${REINPLACE_CMD} -e 's,%%ICONV_LIB%%,${ICONV_LIB},' \
		 -e 's,\(LIBS = -lcrypto\),#\1,g' \
		${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MPLUGINS}
	@${REINPLACE_CMD} -e 's,#ADD_PLUGINS,ADD_PLUGINS,' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
