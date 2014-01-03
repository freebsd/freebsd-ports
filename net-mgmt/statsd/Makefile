# $FreeBSD$

PORTNAME=	statsd
PORTVERSION=	0.7.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/etsy/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	kimor79@yahoo.com
COMMENT=	Simple daemon for easy stats aggregation

RUN_DEPENDS=	node:${PORTSDIR}/www/node

NO_BUILD=	yes

USERS=		statsd
GROUPS=		statsd
USE_RC_SUBR=	statsd
SUB_FILES+=	statsd
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}

post-patch:
	@${REINPLACE_CMD} \
		-e 's;\./;${DATADIR}/;' \
		${WRKSRC}/stats.js

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/backends
	(cd ${WRKSRC}/backends/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/backends)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/lib)
	${CP} ${WRKSRC}/exampleConfig.js ${STAGEDIR}${DATADIR}/exampleConfig.js
	${CP} ${WRKSRC}/exampleProxyConfig.js ${STAGEDIR}${DATADIR}/exampleProxyConfig.js
	${CP} ${WRKSRC}/stats.js ${STAGEDIR}${DATADIR}/stats.js

post-install:
	@${INSTALL_DATA} ${WRKSRC}/exampleConfig.js \
		${STAGEDIR}${PREFIX}/etc/statsd.js.sample

.include <bsd.port.mk>
