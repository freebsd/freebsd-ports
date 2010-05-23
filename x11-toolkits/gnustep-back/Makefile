# New ports collection makefile for:	gnustep-back
# Date created:				27.October 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-back
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	0.19.0
.else
PORTVERSION=	0.17.1
PORTREVISION=	3
.endif
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core
PKGNAMESUFFIX?=	${BACK_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep GUI backend

LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
LIB_DEPENDS+=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_XORG=		xft xrender xmu xext x11
USE_GL=			yes

NO_PACKAGE=	GPL3
MAKE_FLAGS+=		OPTFLAG="${CFLAGS} -I${LOCALBASE}/include"
MAKE_ENV+=		GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
BACKVERSION=		${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}
BREAKS_IF_PEDANTIC=	yes

.if defined(WITH_GNUSTEP_XDPS)
GNUSTEP_DGS_PORT?=	x11/dgs
BUILD_DEPENDS+=		dgs:${PORTSDIR}/${GNUSTEP_DGS_PORT}
LIB_DEPENDS+=		dpstk:${PORTSDIR}/${GNUSTEP_DGS_PORT}
CONFIGURE_ARGS+=	--enable-graphics=xdps --with-name=xdps
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=		BACK=xdps-${BACKVERSION}
PLIST_SUB+=		WITH_XLIB="@comment "
BACK_SUFFIX?=		-xdps
CONFLICTS?=		gunstep-back-0.* gunstep-back-art-0.* gunstep-back-cairo-0.*
.elif defined(WITH_GNUSTEP_LIBART)
LIB_DEPENDS+=		art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl
CONFIGURE_ARGS+=	--enable-graphics=art --with-name=art
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=		BACK=art-${BACKVERSION}
PLIST_SUB+=		WITH_XLIB="@comment "
BACK_SUFFIX?=		-art
CONFLICTS?=		gunstep-back-0.* gunstep-back-xdps-0.* gunstep-back-cairo-0.*
.elif defined(WITH_GNUSTEP_CAIRO)
CFLAGS+=		-I${LOCALBASE}/include/freetype2
LIB_DEPENDS+=		art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl
LIB_DEPENDS+=		cairo.2:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--enable-graphics=cairo --with-name=cairo
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=		BACK=cairo-${BACKVERSION}
PLIST_SUB+=		WITH_XLIB="@comment "
BACK_SUFFIX?=		-cairo
CONFLICTS?=		gunstep-back-0.* gunstep-back-xdps-0.* gunstep-back-art-0.*
.else
CONFIGURE_ARGS+=	--enable-graphics=xlib --with-name=back
CONFIGURE_ARGS+=	--disable-glitz
PLIST_SUB+=		BACK=back-${BACKVERSION}
PLIST_SUB+=		WITH_XLIB=""
CONFLICTS?=		gunstep-back-xdps-0.* gunstep-back-art-0.* gunstep-back-cairo-0.*
.endif

.include <bsd.port.pre.mk>

TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_OBJC_PORT} && make -V TARGLIB)

ADDITIONAL_LDFLAGS+=	-L${TARGLIB}
MAKE_FLAGS+=		messages=yes
PLIST_SUB+=		BACKVERSION=${PORTVERSION:C/([0-9])*[.]([0-9]*).*/\1\2/1}

pre-configure:
.for file in config.guess config.sub install-sh
	@${CP} ${PREFIX}/System/Library/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.post.mk>
