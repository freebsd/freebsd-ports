PORTNAME=	ghostscript
DISTVERSION=	10.01.2
CATEGORIES=	print
MASTER_SITES=	https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs${DISTVERSION:S/.//g}/
PKGNAMESUFFIX=	${GS_MAJOR_VERSION}

MAINTAINER=	michael.osipov@siemens.com
COMMENT=	PostScript and PDF interpreter
WWW=		https://ghostscript.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn \
		libjbig2dec.so:graphics/jbig2dec \
		liblcms2.so:graphics/lcms2 \
		libopenjp2.so:graphics/openjpeg \
		libpaper.so:print/libpaper \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	poppler-data>=0.4.9:graphics/poppler-data \
		urw-base35-fonts>=20200910:x11-fonts/urw-base35-fonts

FLAVORS=	default x11
FLAVOR?=	${FLAVORS:[1]}
default_CONFLICTS_INSTALL=	${PORTNAME}${GS_MAJOR_VERSION}-${FLAVORS:[2]}
x11_PKGNAMESUFFIX=		${GS_MAJOR_VERSION}-${FLAVOR}
x11_CONFLICTS_INSTALL=		${PORTNAME}${GS_MAJOR_VERSION}

USES=		cpe gmake iconv jpeg localbase pkgconfig tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	artifex

CONFLICTS_INSTALL=	ghostscript[789]-base \
			ghostscript[789]-x11 \
			ghostscript9-agpl-base \
			ghostscript9-agpl-x11

EXTRACT_AFTER_ARGS=	--exclude cups/libs \
			--exclude freetype \
			--exclude ijs \
			--exclude jbig2dec \
			--exclude jpeg \
			--exclude lcms2mt \
			--exclude libpng \
			--exclude openjpeg \
			--exclude tiff \
			--exclude zlib

GNU_CONFIGURE=	yes

ALL_TARGET=	so
INSTALL_TARGET=	soinstall

.if ${FLAVOR} == default
CONFIGURE_ARGS+=	--without-x
.endif
.if ${FLAVOR} == x11
USES+=			xorg
USE_XORG=		ice sm x11 xext xt
CONFIGURE_ARGS+=	--with-x
.endif

DATADIR=		${PREFIX}/share/${PORTNAME}/${DISTVERSION}

GS_MAJOR_VERSION=	${DISTVERSION:R:R}
GS_MINOR_VERSION=	${DISTVERSION:R:E}
PLIST_SUB=		GS_MAJOR_VERSION=${GS_MAJOR_VERSION} \
			GS_MINOR_VERSION=${GS_MINOR_VERSION}

CONFIGURE_ARGS+=	--disable-compile-inits \
			--disable-dbus \
			--disable-gtk \
			--disable-dynamic \
			--enable-contrib \
			--enable-fontconfig \
			--enable-freetype \
			--enable-openjpeg \
			--with-fontpath=${LOCALBASE}/share/fonts \
			--with-jbig2dec \
			--with-libiconv=maybe \
			--with-libidn \
			--with-libpaper \
			--with-system-libtiff

OPTIONS_DEFINE=		CUPS IJS TESSERACT
OPTIONS_DEFAULT=	CUPS

IJS_DESC=			Support libijs based Ghostscript devices
TESSERACT_DESC=			Enable bundled Tesseract OCR engine

CUPS_LIB_DEPENDS=		libcups.so:print/cups
CUPS_CONFIGURE_ENABLE=		cups

IJS_LIB_DEPENDS=		libijs.so:print/libijs
IJS_CONFIGURE_WITH=		ijs

TESSERACT_USES=			compiler:c++17-lang
TESSERACT_CONFIGURE_WITH=	tesseract
# No TESSERACT_LIB_DEPENDS=	libtesseract.so:graphics/tesseract
# See https://bugs.ghostscript.com/show_bug.cgi?id=706490

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/man/gs.1

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/gsc ${STAGEDIR}${PREFIX}/bin/gs
	${RM} ${STAGEDIR}${PREFIX}/bin/gsx
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gs \
		${STAGEDIR}${PREFIX}/lib/libgs.so.${GS_MAJOR_VERSION}.${GS_MINOR_VERSION}
	${RM} ${STAGEDIR}${PREFIX}/bin/lprsetup.sh
	${RM} ${STAGEDIR}${PREFIX}/bin/unix-lpr.sh
	${MKDIR} ${STAGEDIR}${PREFIX}/share/color/icc
	${MV} ${STAGEDIR}${DATADIR}/iccprofiles \
		${STAGEDIR}${PREFIX}/share/color/icc/ghostscript
	${RLN} ${STAGEDIR}${PREFIX}/share/color/icc/ghostscript \
		${STAGEDIR}${DATADIR}/iccprofiles
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmap
	${MV} ${STAGEDIR}${DATADIR}/Resource/CMap/Identity* \
		${STAGEDIR}${PREFIX}/share/cmap
	${RM} -r ${STAGEDIR}${DATADIR}/Resource/CMap
	${RLN} ${STAGEDIR}${PREFIX}/share/cmap \
		${STAGEDIR}${DATADIR}/Resource/CMap

.include <bsd.port.mk>
