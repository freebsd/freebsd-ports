PORTNAME=	gnustep-gui
DISTVERSIONPREFIX=	gui-
DISTVERSION=	0_32_0
CATEGORIES=	x11-toolkits gnustep

MAINTAINER=	joe.maloney@icloud.com
COMMENT=	GNUstep GUI library
WWW=		http://www.gnustep.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS+=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libicui18n.so:devel/icu \
		libsndfile.so:audio/libsndfile \
		libao.so:audio/libao \
		libflite.so:audio/flite

USES=		gnustep jpeg pkgconfig xorg
USE_GNUSTEP=	base build
USE_XORG=	x11 xt

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_PROJECT=	libs-gui

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib \
			--with-tiff-include=${LOCALBASE}/include \
			--with-jpeg-library=${LOCALBASE}/lib \
			--with-jpeg-include=${LOCALBASE}/include \
			--with-x \
			--with-x-include=${LOCALBASE}/include \
			--with-x-include=${LOCALBASE}/lib

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
	${REINPLACE_CMD} -e "s|doc=no|doc=yes|" ${WRKSRC}/GNUmakefile

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${GNUSTEP_PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

post-install-DOCS-off:
	@${FIND} -d ${STAGEDIR}${PREFIX}/GNUstep/System/Library/Documentation -type d -empty -delete

.include <bsd.port.mk>
