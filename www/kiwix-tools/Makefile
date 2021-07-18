PORTNAME=	kiwix-tools
DISTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	me@int19h.org
COMMENT=	Command-line Kiwix tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkiwix.so:devel/kiwix-lib \
		libmicrohttpd.so:www/libmicrohttpd \
		libctpp2.so:textproc/ctpp2 \
		libzim.so:devel/libzim

USES=		compiler:c++11-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	kiwix
USE_RC_SUBR=	kiwix_serve

CXXFLAGS_gcc=	-Wno-error=maybe-uninitialized
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/kiwix
	${INSTALL_DATA} files/library.xml ${STAGEDIR}${PREFIX}/share/kiwix

.include <bsd.port.mk>
