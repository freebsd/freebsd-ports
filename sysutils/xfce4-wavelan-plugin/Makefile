# New ports collection makefile for:	xfce-wavelan-plugin
# Date created:				22 May 2004
# Whom:					Manuel Rabade Garica <mig@mig-29.net>
#
# $FreeBSD$
#    $MCom: ports/sysutils/xfce4-wavelan-plugin/Makefile,v 1.1 2006/10/02 20:43:59 ahze Exp $

PORTNAME=	xfce4-wavelan-plugin
PORTVERSION=	0.5.4
PORTREVISION=	13
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Displays various information about a WaveLAN device

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel

.include <bsd.port.mk>
