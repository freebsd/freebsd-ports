# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	9.06
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	http://downloads.ghostscript.com/public/:gs_srcs \
		SF/ghostscript/GPL%20Ghostscript/${PORTVERSION}:gs_srcs \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/GPL/gs${PORTVERSION:S/.//}/:gs_srcs \
		http://www.humblesoft.com/pub/:epag
MASTER_SITE_SUBDIR=	ghostscript/:gs_srcs
PKGNAMESUFFIX=	9
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs ${EPAG_SRCS}:epag
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_AFTER_ARGS=	${EXCLUDE_DIRS:S/^/--exclude /}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ghostscript 9.x PostScript interpreter

LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libidn.so:${PORTSDIR}/dns/libidn \
		libjbig2dec.so:${PORTSDIR}/graphics/jbig2dec \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpaper.so:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[78]-[0-9]* \
		ghostscript[78]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USES=		gmake pkgconfig:build tar:bzip2
WANT_GNOME=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		SOC_LOADER="dxmainc.c"
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--enable-contrib \
		--enable-dynamic \
		--with-system-libtiff \
		--with-ijs \
		--with-libidn \
		--without-jasper \
		--with-libpaper \
		--with-drivers=""
CPPFLAGS+=	-DUPD_SIGNAL=0 -I. \
		-I${WRKSRC}/lcms/include \
		-I${LOCALBASE}/include/libpng \
		-I${WRKSRC}/openjpeg/libopenjpeg \
		-I${WRKSRC}/openjpeg \
		-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
XCFLAGS=	${PTHREAD_CFLAGS} \
		-DA4
XLDFLAGS=	${PTHREAD_LIBS}

PLIST_SUB=	GS_VERSION="${PORTVERSION}" \
		X11BITS=${X11BITS}
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PORTVERSION=${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS_DEFINE=	X11 DOCS CUPS FONTCONFIG ICONV GTK2
OPTIONS_DEFAULT=X11 DOCS CUPS FONTCONFIG ICONV
OPTIONS_SUB=	yes
FONTCONFIG_DESC=Enable fontconfig support
NO_OPTIONS_SORT=yes

EXCLUDE_DIRS=	freetype jbig2dec jpeg expat jasper lcms lcms2 libpng tiff zlib

.include "Makefile.drivers"
.include <bsd.port.options.mk>

MASTERDIR?=	${.CURDIR}
.include "${MASTERDIR}/files/Makefile.drivers_post"

FONTCONFIG_LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
FONTCONFIG_CONFIGURE_ENABLE=	fontconfig

# FT_BRIDGE=1 by default
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2
MAKE_ENV+=	FT_BRIDGE=1

ALL_TARGET=	so
INSTALL_TARGET=	soinstall
USE_LDCONFIG=	yes
PLIST_SUB+=	SHLIB_VER="${PORTVERSION:R}"

PORTDOCS=	japanese chp2200 epson740 lxm3200-tweaked md2k_md5k
PORTDOC_FILES=	japanese/Gdevlips.htm japanese/README.gs550j		\
	japanese/cdj880.txt japanese/dj505j.txt japanese/djgpp.txt	\
	japanese/gdev10v.txt japanese/gdevalps.txt			\
	japanese/gdevcd8.txt japanese/gdevdmpr.txt			\
	japanese/gdevfmlbp.txt japanese/gdevj100.txt			\
	japanese/gdevlbp3.txt japanese/gdevmag.txt			\
	japanese/gdevmd2k.txt japanese/gdevmjc.txt			\
	japanese/gdevml6.txt japanese/gdevp201.txt japanese/gs261j.euc	\
	japanese/gs261j.txt chp2200/AUTHORS chp2200/INSTALL		\
	epson740/README epson740/upp-HowTo-to-be			\
	lxm3200-tweaked/LICENSE lxm3200-tweaked/README			\
	lxm3200-tweaked/RELEASE_NOTES					\
	lxm3200-tweaked/Z12-Z31-QuickSetup md2k_md5k/README.jis

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g ; \
	    s|%%GS_VERSION%%|${PORTVERSION}|g' \
	    ${WRKSRC}/contrib/japanese/dmp_site.ps

pre-build-drivers.mak:
	@${ECHO_CMD} '# automatically generated' > ${WRKSRC}/base/drivers.mak
	@${ECHO_CMD} 'DEVICE_DEVS=$${DISPLAY_DEV}' >> ${WRKSRC}/base/drivers.mak
.for N in ${DEVS_LIST}
	@${ECHO_CMD} '${N:S/^/DEVICE_/:S/^DEVICE_DISPLAY_DEV/DISPLAY_DEV/}=' >> ${WRKSRC}/base/drivers.mak
.endfor
.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_MULTI_X11:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_ICONV:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_SVGALIB:MGS_*:S/^GS_//}
.for N in ${DEVS_LIST}
.if ${PORT_OPTIONS:MGS_${D}}
.if !defined(OPTIONS_UNSET) || !${OPTIONS_UNSET:MGS_${D}}
.for X in ${${N:S/^/DEVICE_/:S/^DEVICE_DISPLAY_DEV/DISPLAY_DEV/}:M${D}.dev}
	@${ECHO_CMD} '${N:S/^/DEVICE_/:S/^DEVICE_DISPLAY_DEV/DISPLAY_DEV/}+= $$(DD)${D}.dev'  >> ${WRKSRC}/base/drivers.mak
.endfor
.endif
.endif
.endfor
.endfor

pre-build: pre-build-drivers.mak
	${MKDIR} ${WRKSRC}/obj
	${MKDIR} ${WRKSRC}/bin

pre-install:
	cd ${WRKSRC}/Resource/Init && ${RM} -f \
		gs_statd.ps.orig gs_ttf.ps.orig pdf_font.ps.orig

pre-su-install:
	${MKDIR} ${STAGEDIR}${DATADIR}

post-install-docs:
	${MKDIR} ${WRKSRC}/contrib/japanese
	${INSTALL_DATA} ${WRKSRC}/contrib/japanese/doc/* ${WRKSRC}/contrib/japanese
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/contrib && \
		${TAR} -cf - ${PORTDOC_FILES} | \
		( cd ${STAGEDIR}${DOCSDIR} && ${TAR} -xof - )

post-install:
	${LN} -sf gsc ${STAGEDIR}${PREFIX}/bin/gs
	${LN} -s -f ${LOCALBASE}/share/fonts/CIDFont \
		${STAGEDIR}${DATADIR}/${PORTVERSION}/Resource/CIDFont/fonts

.if ${PORT_OPTIONS:MDOCS}
post-install: post-install-docs
.endif

.include <bsd.port.mk>
