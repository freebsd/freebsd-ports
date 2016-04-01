# $FreeBSD$

PORTNAME=	statsd
PORTVERSION=	0.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	kimor79@yahoo.com
COMMENT=	Simple daemon for easy stats aggregation

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	node:www/node

NO_BUILD=	yes
NO_ARCH=	yes

USERS=		statsd
GROUPS=		statsd
USE_RC_SUBR=	statsd
SUB_FILES+=	statsd
SUB_LIST+=	USERS=${USERS} GROUPS=${GROUPS}
USE_GITHUB=	yes
GH_ACCOUNT=	etsy

post-patch:
	@${REINPLACE_CMD} \
		-e 's;\./;${DATADIR}/;' \
		${WRKSRC}/stats.js

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/backends
	(cd ${WRKSRC}/backends/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/backends)
	${MKDIR} ${STAGEDIR}${DATADIR}/lib
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/lib)
	${INSTALL_DATA} ${WRKSRC}/exampleConfig.js ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/exampleProxyConfig.js ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/stats.js ${STAGEDIR}${DATADIR}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/exampleConfig.js \
		${STAGEDIR}${PREFIX}/etc/statsd.js.sample

.include <bsd.port.mk>
