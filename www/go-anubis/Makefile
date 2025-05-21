PORTNAME=	anubis
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.1
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	go-

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Anti-scraper web proxy using browser-based proof-of-work challenges
WWW=		https://anubis.techaro.lol/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.24
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/techarohq/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/TecharoHQ/anubis.Version=v${DISTVERSION}"

PLIST_FILES=	sbin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}

.include <bsd.port.mk>
