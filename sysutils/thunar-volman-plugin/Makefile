# New ports collection makefile for:	thunar-volman-plugin
# Date created:				24 Januar 2007
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	thunar-volman
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Device manager plugin.

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo thunar

.include <bsd.port.mk>
