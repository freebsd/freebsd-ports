PORTNAME=	tvterm
PORTVERSION=	g20251031
CATEGORIES=	sysutils

MAINTAINER=	tiga@FreeBSD.org
COMMENT=	Terminal emulator powered by Turbo Vision
WWW=		https://github.com/magiblot/tvterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libtvision.so:devel/tvision \
		libvterm.so:devel/libvterm

USES=		cmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	magiblot
GH_TAGNAME=	8d12913

CMAKE_ON=	BUILD_SHARED_LIBS \
		TVTERM_USE_SYSTEM_LIBVTERM \
		TVTERM_USE_SYSTEM_TVISION

.include <bsd.port.mk>
