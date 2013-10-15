# Created by: James Earl <jdearl@telus.net>
# $FreeBSD$

PORTNAME=	xfce4-wm-themes
PORTVERSION=	4.10.0
PORTREVISION=	1
CATEGORIES=	misc xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/art/xfwm4-themes/${PORTVERSION:R}
DISTNAME=	xfwm4-themes-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Additional themes for xfwm4

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined
USES=	gmake

.include <bsd.port.mk>
