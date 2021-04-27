# Created by: Thomas Gellekum <tg@FreeBSD.org>

PORTNAME=	gnustep-gui
DISTVERSIONPREFIX=	gui-
DISTVERSION=	0_28_0
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnustep

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNUstep GUI library

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS+=	libtiff.so:graphics/tiff
LIB_DEPENDS+=	libpng.so:graphics/png
LIB_DEPENDS+=	libgif.so:graphics/giflib
LIB_DEPENDS+=	libicui18n.so:devel/icu
LIB_DEPENDS+=	libsndfile.so:audio/libsndfile
LIB_DEPENDS+=	libao.so:audio/libao
LIB_DEPENDS+=	libflite.so:audio/flite

BROKEN_FreeBSD_11=	compiler segfault

USES=		gnustep jpeg pkgconfig xorg
USE_GNUSTEP=	base build
USE_XORG=	x11 xt

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_PROJECT=	libs-gui

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-x-include=${LOCALBASE}/lib

MAKE_FLAGS+=	OPTFLAG="${CFLAGS}"

PLIST_SUB+=	BASEVERSION=${PORTVERSION:C/[.][0-9]*$//1}

OPTIONS_DEFINE=	DOCS CUPS ASPELL
OPTIONS_DEFAULT=	CUPS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	texi2html:textproc/texi2html \
			texi2pdf:print/texinfo

CUPS_CONFIGURE_ENABLE=		cups
CUPS_LIB_DEPENDS+=	libcups.so:print/cups
ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=	aspell

USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

post-patch:
	${REINPLACE_CMD} -e "s|libpng/png.h|png.h|" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

post-install-DOCS-off:
	@${FIND} -d ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Documentation -type d -empty -delete

.include <bsd.port.mk>
