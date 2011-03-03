# New ports collection makefile for:	dictionary plugin for xfce4
# Date created:				23. January 2007
# Whom:					Oliver Lehmann (oliver@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-dict
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	textproc xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4
PKGNAMESUFFIX=	-plugin

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Xfce Plugin for searching for the translation or explanation of a word

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
MAN1=		xfce4-dict.1

.include <bsd.port.mk>
