PORTNAME=	monolith
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.1
PORTREVISION=	5
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	CLI tool for saving complete web pages as a single HTML file
WWW=		https://github.com/Y2Z/monolith

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	Y2Z

PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
