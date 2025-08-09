PORTNAME=	rgb-tui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1-6
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g207f0d9
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create and get color codes from the terminal using a nice interface
WWW=		https://github.com/ArthurSonzogni/rgb-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libclip.so:x11/clip \
		libfmt.so:devel/libfmt \
		libftxui-screen.so:devel/ftxui

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	ArthurSonzogni

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
