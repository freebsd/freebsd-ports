# New ports collection makefile for:    gtk-smooth-engine
# Date created:         19 November 2003
# Whom:                 Anish Mistry
#
# $FreeBSD$
#

PORTNAME=	gtk-smooth-engine
PORTVERSION=	0.5.8
PORTREVISION=	4
CATEGORIES=	x11-themes gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	smooth-engine

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Flexible GTK Theme Engine

BROKEN=		Does not compile

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
WANT_GNOME=	yes
CONFIGURE_ENV=	X11BASE="${X11BASE}"

CONFLICTS=	gnome-themes-[0-9]*

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!=""
WITH_GTK2=	yes
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
WITH_GTK12=	yes
.endif

# if neither gtk is detected automatically pull in gtk2
.if !defined(WITH_GTK12) && !defined(WITH_GTK2)
WITH_GTK2=	yes
.endif

.if defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--enable-gtk-2
PLIST_SUB+=	GTK2:=""
.else
CONFIGURE_ARGS+=--disable-gtk-2
PLIST_SUB+=	GTK2:="@comment "
.endif

.if defined(WITH_GTK12)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=--enable-gtk-1
PLIST_SUB+=	GTK1:=""
.else
CONFIGURE_ARGS+=--disable-gtk-1
PLIST_SUB+=	GTK1:="@comment "
.endif

pre-everything::
.if !defined(WITH_GTK2)
	@${ECHO_MSG} "To enable gtk2 support define WITH_GTK2."
.endif

.if !defined(WITH_GTK12)
	@${ECHO_MSG} "To enable gtk12 support define WITH_GTK12."
.endif

.include <bsd.port.post.mk>
