PORTNAME=	xurls
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Extract urls from text or files
WWW=		https://github.com/mvdan/xurls

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	mvdan.cc/xurls/v2
GO_TARGET=	${WRKSRC}/cmd/${PORTNAME}:${PREFIX}/bin/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-w -s -X=main.version=${DISTVERSIONPREFIX}${DISTVERSION}"

PLIST_FILES=	bin/xurls

.include <bsd.port.mk>
