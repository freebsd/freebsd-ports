# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXft
PORTVERSION=	2.1.13
CATEGORIES=	x11-fonts

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

XORG_CAT=	lib
USE_XORG=	xproto:both xrender

MAN1=		xft-config.1
MAN3=		Xft.3

.include <bsd.port.mk>
