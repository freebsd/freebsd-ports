PORTNAME=	httping
PORTVERSION=	4.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ping-like tool for HTTP requests
WWW=		https://www.vanheusden.com/httping/ \
		https://github.com/folkertvanheusden/HTTPing

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig localbase:ldflags ssl

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man/man1
CMAKE_ON=	USE_SSL

USE_GITHUB=	yes
GH_ACCOUNT=	folkertvanheusden
GH_PROJECT=	HTTPing

OPTIONS_DEFINE=	DOCS FFTW3 NCURSES NLS
OPTIONS_DEFAULT=NCURSES
OPTIONS_SUB=	yes
FFTW3_IMPLIES=	TUI

FFTW3_CMAKE_BOOL=	USE_FFTW3
FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3
NCURSES_CMAKE_BOOL=	USE_TUI
NCURSES_LDFLAGS=	${NCURSESLIBS}
NCURSES_USES=		ncurses
NLS_CMAKE_BOOL=		USE_GETTEXT
NLS_USES=		gettext-runtime gettext-tools

.include <bsd.port.mk>
