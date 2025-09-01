PORTNAME=	mdcat
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.7.1
PORTREVISION=	6
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Cat for markdown
WWW=		https://github.com/swsnr/mdcat

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	swsnr

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
