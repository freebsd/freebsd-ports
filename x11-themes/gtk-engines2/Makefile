# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gtk-engines2/Makefile,v 1.82 2010/04/19 10:51:27 kwm Exp $

PORTNAME=	gtk-engines2
PORTVERSION=	2.20.2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Theme engine for the GTK+-2.0 toolkit

CONFLICTS=	gtk-smooth-engine-[0-9]* clearlooks-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20 intlhack ltasneededhack
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ANIMATION
ANIMATION_DESC=	Experimental animated progressbars

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANIMATION}
CONFIGURE_ARGS+=	--enable-animation
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|glib.*\.h>|glib.h>|g' \
		${WRKSRC}/engines/clearlooks/src/animation.c

post-install:
	@(cd ${WRKSRC}/po && ${GMAKE} install)

.include <bsd.port.mk>
