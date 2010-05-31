# New ports collection makefile for:   lxappearance
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxappearance
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11-themes gnome
MASTER_SITES=	SF/lxde/LXAppearance

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A desktop-independent theme switcher for GTK+

USE_GNOME=	gnomehack gtk20 intlhack
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		lxappearance.1

.include <bsd.port.mk>
