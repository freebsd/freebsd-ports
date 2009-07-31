# New ports collection makefile for:   guile-gtk
# Date created:        1 January 2000
# Whom:                Matt Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/guile-gtk/Makefile,v 1.2 2006/09/10 00:51:17 mezz Exp $

PORTNAME=	guile-gtk
PORTVERSION=	0.60
PORTREVISION=	5
CATEGORIES=	x11-toolkits scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Guile binding library for GTK+

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

USE_GMAKE=	yes
USE_GNOME=	gnometarget ltverhack gdkpixbuf libglade
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-gtkgl=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

INFO=		guile-gtk

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|gtk-1\.2/||g'

.include <bsd.port.mk>
