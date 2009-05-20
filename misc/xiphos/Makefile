# New ports collection makefile for: xiphos
# Date created:   February 2, 2009
# Whom:           Thomas Abthorpe <tabthorpe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xiphos
PORTVERSION=	3.1
CATEGORIES=	misc gnome
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gnomesword

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	A bible interface utilizing the sword framework

RUN_DEPENDS=	${LOCALBASE}/lib/gnome-spell/libgnome-spell-component-0.3.so:${PORTSDIR}/textproc/gnome-spell \
		${LOCALBASE}/lib/libsword-1.5.11.so:${PORTSDIR}/misc/sword
BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick

USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gal2 gtkhtml3 gnomelibs intlhack gnomedocutils
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-maintainer-mode --enable-paratab

OPTIONS=	XULRUNNER	"Build with xulrunner (default)" off \
		GTKHTML		"Build with gtkhtml" off

.include <bsd.port.pre.mk>

.if defined(WITH_XULRUNNER) && defined(WITH_GTKHTML)
IGNORE=		choose only one of XULRUNNER or GTKHTML
.endif

.if defined(WITH_GTKHTML) || defined(WITHOUT_XULRUNNER)
CONFIGURE_ARGS+=	--enable-gtkhtml --disable-gecko
.endif

.if !defined(WITHOUT_XULRUNNER) || !defined(WITH_GTKHTML)
USE_GECKO=	xulrunner
CONFIGURE_ARGS+=	--with-gecko=${GECKO} --disable-gtkhtml
.endif

.include <bsd.port.post.mk>
