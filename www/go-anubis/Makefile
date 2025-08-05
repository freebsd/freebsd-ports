PORTNAME=	anubis
DISTVERSIONPREFIX=	v
DISTVERSION=	1.21.3
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://github.com/techarohq/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMEPREFIX=	go-
DISTNAME=	anubis-src-vendor-npm-${DISTVERSION}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Anti-scraper web proxy using browser-based proof-of-work challenges
WWW=		https://anubis.techaro.lol/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,no_targets
USE_RC_SUBR=	${PORTNAME}

ALL_TARGET=	prebaked-build

post-patch:
	@${FIND} ${WRKSRC}/data \( -name "*.yaml" -or -name "*.json" \) \
		| ${XARGS} ${REINPLACE_CMD} -i '' -e 's|(data)|${DATADIR}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/var/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/var/robots2policy \
		${STAGEDIR}${PREFIX}/sbin/robots2policy
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} '-not -name *.go'

.include <bsd.port.mk>
