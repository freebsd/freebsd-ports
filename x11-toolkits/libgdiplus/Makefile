# New ports collection makefile for:		libgdiplus
# Date created:					20040820
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.46 2007/12/13 19:37:18 killfill Exp $
#

PORTNAME=	libgdiplus
PORTVERSION=	2.6.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	GDI+ API for System.Windows.Forms in Mono

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget glib20
USE_GMAKE=	yes
USE_XLIB=	yes
USE_LDCONFIG=   yes
LIBTOOLFILES=	configure cairo/configure
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
# Included cairo does not work for us.  Enable below when Mono catches
# up with our port.  For now, use included but patch out glitz manually.
#CONFIGURE_ARGS+= --with-cairo=installed
CPPFLAGS+=	-DPNG_DEPSTRUCT=

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/cairo/src/cairo-png.c
	${REINPLACE_CMD} -e 's|libpng12|libpng14|' \
		${WRKSRC}/configure

.include <bsd.port.pre.mk>

# Avoid build error on 64-bit architectures
.if (${ARCH} == "amd64") || (${ARCH} == "ia64") || (${ARCH} == "sparc64")
CFLAGS+=        -fPIC
.endif

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
