# New ports collection makefile for:		libgdiplus
# Date created:					20040820
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.34 2007/02/07 15:40:01 killfill Exp $
#

PORTNAME=	libgdiplus
PORTVERSION=	1.2.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.go-mono.com/sources/${PORTNAME}/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	GDI+ API for System.Windows.Forms in Mono

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack gnometarget glib20
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_XLIB=	yes
LIBTOOLFILES=	configure cairo/configure
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
# Included cairo does not work for us.  Enable below when Mono catches
# up with our port.  For now, use included but patch out glitz manually.
#CONFIGURE_ARGS+= --with-cairo=installed

.include <bsd.port.pre.mk>

# Avoid build error on 64-bit architectures
.if (${ARCH} == "amd64") || (${ARCH} == "ia64") || (${ARCH} == "sparc64")
CFLAGS+=        -fPIC
.endif

.if ${OSVERSION} < 503000
IGNORE= does not build and is useless without working Mono
.endif

.include <bsd.port.post.mk>
