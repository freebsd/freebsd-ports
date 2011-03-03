# New ports collection makefile for:	thunar-volman-plugin
# Date created:				24 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	thunar-volman
PORTVERSION=	0.3.80
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Device manager plugin.

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

BROKEN=		Does not work with xfce 4.8

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo thunar

.include <bsd.port.mk>
