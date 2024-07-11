PORTNAME=	httping
PORTVERSION=	3.7a
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

USE_GITHUB=	yes
GH_ACCOUNT=	folkertvanheusden
GH_PROJECT=	HTTPing
GH_TAGNAME=	bb94c6d

OPTIONS_DEFINE=	DOCS FFTW NCURSES NLS
OPTIONS_DEFAULT=NCURSES
OPTIONS_SUB=	yes

FFTW_CMAKE_BOOL=	USE_FFTW
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
NCURSES_CMAKE_BOOL=	USE_TUI
NCURSES_LDFLAGS=	${NCURSESLIBS}
NCURSES_USES=		ncurses
NLS_CMAKE_BOOL=		USE_GETTEXT
NLS_USES=		gettext-runtime gettext-tools

.include <bsd.port.mk>
