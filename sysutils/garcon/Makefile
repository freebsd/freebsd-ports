# New ports collection makefile for:	garcon
# Date created:				11 January 2011
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	garcon
PORTVERSION=	0.1.5
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/libs/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 essential utilities and scripts

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv

.include <bsd.port.mk>

