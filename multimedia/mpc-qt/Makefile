# $FreeBSD$

PORTNAME=	mpc-qt
DISTVERSION=	0.0.0.s20161230
CATEGORIES=	multimedia audio
MASTER_SITES=	https://aur.archlinux.org/cgit/aur.git/plain/${PORTNAME}.desktop?h=${PORTNAME}-git&id=b1a6b91&dummy=/:desktop
DISTFILES=	${PORTNAME}.desktop:desktop
EXTRACT_ONLY=	${DISTFILES:N*\:desktop:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Qt 5 clone of Media Player Classic based on libmpv

LICENSE=	GPLv2

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USE_GITHUB=	yes
GH_ACCOUNT=	cmdrkotori
GH_TAGNAME=	54b0be7

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake
USE_QT5=	qmake_build buildtools_build core gui network widgets x11extras
USE_GL=		gl
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/images/bitmaps/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
