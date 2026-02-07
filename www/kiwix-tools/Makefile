PORTNAME=	kiwix-tools
DISTVERSION=	3.7.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://download.kiwix.org/release/kiwix-tools/

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Command-line Kiwix tools (serve, manage, search)
WWW=		https://github.com/kiwix/kiwix-tools

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkiwix.so.13:devel/libkiwix13 \
		libzim.so:devel/libzim

USES=		compiler:c++17-lang meson pkgconfig tar:xz

CXXFLAGS_gcc=	-Wno-error=maybe-uninitialized
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/kiwix
	${INSTALL_DATA} files/library.xml ${STAGEDIR}${PREFIX}/share/kiwix

.include <bsd.port.mk>
