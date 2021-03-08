# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	9.52
PORTREVISION=	15
CATEGORIES=	print
MASTER_SITES=	https://github.com/ArtifexSoftware/ghostpdl-downloads/releases/download/gs${PORTVERSION:S/.//}/
PKGNAMESUFFIX=	9-agpl-base

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	PostScript and PDF interpreter

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	jbig2dec>=0.17:graphics/jbig2dec
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn \
		libjbig2dec.so:graphics/jbig2dec \
		libpaper.so:print/libpaper \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	poppler-data>=0.4.9:graphics/poppler-data

USES=		cpe gmake iconv jpeg localbase pkgconfig tar:xz
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

CONFLICTS_INSTALL= \
		ghostscript[789]-[0-9]* \
		ghostscript[789]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*
CPE_VENDOR=	artifex
DATADIR=	${PREFIX}/share/${PORTNAME}/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}/${PORTVERSION}
EXTRACT_AFTER_ARGS= \
	--exclude cups/libs \
	--exclude freetype \
	--exclude ijs \
	--exclude jbig2dec \
	--exclude jpeg \
	--exclude libpng \
	--exclude openjpeg \
	--exclude zlib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-compile-inits \
		--disable-dbus \
		--disable-gtk \
		--enable-contrib \
		--enable-dynamic \
		--enable-fontconfig \
		--enable-freetype \
		--with-drivers=ALL \
		--with-fontpath=${LOCALBASE}/share/fonts \
		--with-jbig2dec \
		--with-libiconv=maybe \
		--with-libidn \
		--with-libpaper \
		--with-system-libtiff \
		--without-x
ALL_TARGET=	so
INSTALL_TARGET=	soinstall
PLIST_SUB=	GS_VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS CUPS IJS JPEG2000
OPTIONS_DEFAULT=CUPS
OPTIONS_SUB=	yes

CUPS_CONFIGURE_ENABLE=	cups
CUPS_LIB_DEPENDS=	libcupsimage.so:print/cups

IJS_CONFIGURE_WITH=	ijs
IJS_DESC=		Support libijs based Ghostscript devices
IJS_LIB_DEPENDS=	libijs.so:print/libijs

JPEG2000_CONFIGURE_ENABLE=	openjpeg
JPEG2000_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/gsc ${STAGEDIR}${PREFIX}/bin/gs
	${RM} ${STAGEDIR}${PREFIX}/bin/gsx
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgs.so
	${MKDIR} ${STAGEDIR}${PREFIX}/share/color/icc
	${MV} ${STAGEDIR}${DATADIR}/iccprofiles \
		${STAGEDIR}${PREFIX}/share/color/icc/ghostscript
	${RLN} ${STAGEDIR}${PREFIX}/share/color/icc/ghostscript \
		${STAGEDIR}${DATADIR}/iccprofiles
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/doc
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmap
	${MV} ${STAGEDIR}${DATADIR}/Resource/CMap/Identity* \
		${STAGEDIR}${PREFIX}/share/cmap
	${RM} -r ${STAGEDIR}${DATADIR}/Resource/CMap
	${RLN} ${STAGEDIR}${PREFIX}/share/cmap \
		${STAGEDIR}${DATADIR}/Resource/CMap

.include <bsd.port.mk>
