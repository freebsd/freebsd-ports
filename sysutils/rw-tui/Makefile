PORTNAME=	rw-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gfd62cef
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Read & Write Everything (only memory for now on FreeBSD)
WWW=		https://github.com/LeeKyuHyuk/rw-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libftxui-screen.so:devel/ftxui

USES=		cmake #localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	LeeKyuHyuk

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
