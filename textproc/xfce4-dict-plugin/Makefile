# New ports collection makefile for:	dictionary plugin for xfce4
# Date created:				23. January 2007
# Whom:					Oliver Lehmann (oliver@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-dict-plugin
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	textproc xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Xfce Plugin for searching for the translation or explanation of a word

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
USE_XLIB=	yes

.include <bsd.port.mk>
