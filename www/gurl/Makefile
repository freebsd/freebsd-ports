PORTNAME=	gurl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.3
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Terminal cURL-like HTTP tool with delightful JSON & header support

LICENSE=	APACHE20

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	skunkwerks

PLIST_FILES=	bin/gurl

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gurl

.include <bsd.port.mk>
