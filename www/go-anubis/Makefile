PORTNAME=	anubis
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.1
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

PLIST_FILES=	sbin/${PORTNAME}

ALL_TARGET=	prebaked-build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/var/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
