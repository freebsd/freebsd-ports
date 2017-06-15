# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-engines2/Makefile,v 1.82 2010/04/19 10:51:27 kwm Exp $

PORTNAME=	gtk-engines2
PORTVERSION=	2.20.2
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME/sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the GTK+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_GNOME=	gtk20 intlhack
USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ANIMATION
ANIMATION_DESC=	Experimental animated progressbars

ANIMATION_CONFIGURE_ENABLE=	animation

post-patch:
	@${REINPLACE_CMD} -e 's|glib.*\.h>|glib.h>|g' \
		${WRKSRC}/engines/clearlooks/src/animation.c

post-install:
	@(cd ${WRKSRC}/po && ${MAKE_CMD} install DESTDIR=${STAGEDIR})

.include <bsd.port.mk>
