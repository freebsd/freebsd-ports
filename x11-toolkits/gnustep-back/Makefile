# New ports collection makefile for:	gnustep-back
# Date created:				27.October 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gnustep-back
PORTVERSION=	0.9.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	core

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep GUI backend

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft

USE_XLIB=		yes
PREFIX=			${LOCALBASE}/GNUstep
NO_MTREE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--with-tiff-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-tiff-include=${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-jpeg-library=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-jpeg-include=${LOCALBASE}/include
#CPPFLAGS+=		-I${LOCALBASE}/include/freetype2
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
USE_GMAKE=		yes
USE_GNUSTEP=	yes
USE_GNUSTEP_GUI=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
MAKE_FLAGS+=		OPTFLAG="${CFLAGS} -I${X11BASE}/include"
BREAKS_IF_PEDANTIC=	yes

.if defined(WITH_GNUSTEP_XDPS)
CONFIGURE_ARGS+=	--enable-graphics=xdps --with-name=xdps
PLIST_SUB+=		BACK=xdps
PLIST_SUB+=		USE_XLIB="@comment " USE_XDPS="" USE_ART="@comment "
PKGNAMESUFFIX?=		-xdps
.else
.if defined(WITH_GNUSTEP_LIBART)
LIB_DEPENDS+=		art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2
CONFIGURE_ARGS+=	--enable-graphics=art --with-name=art
PLIST_SUB+=		BACK=art USE_XLIB="@comment "
PLIST_SUB+=		USE_XLIB="@comment " USE_XDPS="@comment " USE_ART=""
PKGNAMESUFFIX?=		-art
.else
CONFIGURE_ARGS+=	--enable-graphics=xlib --with-name=back
PLIST_SUB+=		BACK=back
PLIST_SUB+=		USE_XLIB="" USE_XDPS="@comment " USE_ART="@comment "
.endif
.endif

.include <bsd.port.pre.mk>

TARGLIB!=	(cd ${PORTSDIR}/${GNUSTEP_OBJC_PORT} && make -V TARGLIB)

ADDITIONAL_LDFLAGS+=	-L${TARGLIB}
MAKE_ENV+=		ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"
MAKE_FLAGS+=		messages=yes

.if ${OSVERSION} < 500000
ADDITIONAL_LDFLAGS+=	-L/usr/lib -lcipher
MAKE_ENV+=		ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"
.endif

post-extract:
.for file in config.guess config.sub install-sh
	@${CP} ${PREFIX}/System/Makefiles/${file} ${WRKSRC}
.endfor

.include <bsd.port.post.mk>
