# New ports collection makefile for:    gtk-sharp
# Date created:         2003-01-01
# Whom:                 Juli Mallett
#
# $FreeBSD$
#

PORTNAME=	gtk-sharp
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtk-sharp

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ and GNOME interfaces for the .NET runtime

BROKEN=		"Does not compile"

BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono

# XXX Should conditionalise all the different parts of gtk# maybe.

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui libgnomedb
MAKEFILE=	makefile

.include <bsd.port.mk>
