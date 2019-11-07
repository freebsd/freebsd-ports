# $FreeBSD$

PORTNAME=	gabedit
DISTVERSION=	2.5.1
PORTREVISION=	3
CATEGORIES=	science
#MASTER_SITES=	http://prdownloads.sourceforge.net/${PORTNAME}/ # old SF-based source
#DISTNAME=	GabeditSrc${DISTVERSION:S/.//g}
MASTER_SITES=	https://sites.google.com/site/allouchear/Home/gabedit/download/ # development version now on sites.google.com, browse to the same URL for details
DISTNAME=	GabeditSrc${DISTVERSION:S/.//g}_061218

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for several chemistry software packages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License

BROKEN_i386=	undefined reference to `__atomic_load'

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		compiler:c++11-lang gettext-runtime gl gmake gnome pkgconfig \
		xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango pangox-compat
USE_GL=		gl glu
USE_XORG=	ice sm x11 xmu xt
INSTALLS_ICONS=	yes

BINARY_ALIAS=	make=gmake

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop

ICON_SIZES=	16 24 32 48
.for SZ in ${ICON_SIZES}
PLIST_FILES+=	share/icons/hicolor/${SZ}x${SZ}/apps/${PORTNAME}.png
.endfor

OPTIONS_DEFINE=		OPENMP
OPTIONS_DEFAULT=	OPENMP

OPENMP_LIB_DEPENDS=	libgomp.so:devel/openmp

post-patch:
	@${REINPLACE_CMD} 's|/usr/|${PREFIX}/|; s| -O2| ${CFLAGS}|; s|gcc|${CC}|' ${WRKSRC}/CONFIG

post-patch-OPENMP-off:
	@${REINPLACE_CMD} 's|enable_omp = 1|enable_omp = 0|' ${WRKSRC}/CONFIG

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/utils/Others/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
.for SZ in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/Gabedit${SZ}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${SZ}x${SZ}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
