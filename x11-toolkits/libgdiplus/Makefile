# New ports collection makefile for:		libgdiplus
# Date created:					20040820
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.24 2006/02/05 03:07:29 tmclau02 Exp $
#

PORTNAME=	libgdiplus
PORTVERSION=	1.1.13.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.go-mono.com/sources/libgdiplus-1.1/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	GDI+ API for System.Windows.Forms in Mono

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnomehack gnometarget glib20
USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFILES=	configure cairo/configure
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
# Included cairo does not work for us.  Enable below when Mono catches
# up with our port.  For now, use included but patch out glitz manually.
#CONFIGURE_ARGS+= --with-cairo=installed

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE= does not build and is useless without working Mono
.endif

.include <bsd.port.post.mk>
