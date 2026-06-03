PORTNAME=	gurl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Terminal cURL-like HTTP tool with delightful JSON & header support
WWW=		https://github.com/skunkwerks/gurl

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	skunkwerks

GO_BUILDFLAGS=	-ldflags="-X github.com/skunkwerks/gurl/version.Version=${DISTVERSIONPREFIX}${DISTVERSION}"

PLIST_FILES=	bin/gurl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gurl

.include <bsd.port.mk>
