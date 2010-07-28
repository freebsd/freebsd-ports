# New ports collection makefile for:		libgdiplus
# Date created:					20040820
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	libgdiplus
PORTVERSION=	2.6.7
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GDI+ API for System.Windows.Forms in Mono

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget glib20
USE_GMAKE=	yes
USE_XLIB=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

PLIST_FILES=	lib/libgdiplus.a \
		lib/libgdiplus.la \
		lib/libgdiplus.so \
		lib/libgdiplus.so.0 \
		libdata/pkgconfig/libgdiplus.pc

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
