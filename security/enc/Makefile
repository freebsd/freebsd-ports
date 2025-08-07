PORTNAME=	enc
DISTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Modern and friendly CLI alternative to GnuPG
WWW=		https://github.com/life4/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	life4
GO_MOD_DIST=	github
GO_MODULE=	github.com/life4/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
