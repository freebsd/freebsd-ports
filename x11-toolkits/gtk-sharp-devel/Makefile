# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	0.11
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ and GNOME interfaces for the .NET runtime

BUILD_DEPENDS+=	mono:${PORTSDIR}/lang/mono
LIB_DEPENDS+=	pgeasy.2:${PORTSDIR}/databases/postgresql72

# XXX Should conditionalise all the different parts of gtk# maybe.

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgda2 libgnomeui libgnomedb

.include <bsd.port.mk>
