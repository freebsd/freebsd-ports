PORTNAME=	tvterm
PORTVERSION=	g20250324
CATEGORIES=	sysutils

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Terminal emulator powered by Turbo Vision
WWW=		https://github.com/magiblot/tvterm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libvterm.so:devel/libvterm

USES=		cmake ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	magiblot
GH_PROJECT=	tvision:tv
GH_SUBDIR=	deps/tvision:tv
GH_TAGNAME=	feedbf7 d9bc009:tv

CMAKE_ON=	TVTERM_USE_SYSTEM_LIBVTERM \
		BUILD_SHARED_LIBS

.include <bsd.port.mk>
