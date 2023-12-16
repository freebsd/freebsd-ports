PORTNAME=	wiki-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple and easy to use Wikipedia Text User Interface
WWW=		https://github.com/Builditluc/wiki-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Builditluc

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
