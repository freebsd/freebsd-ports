# New ports collection makefile for:	xfburn
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xfburn
PORTVERSION=	0.3.91
CATEGORIES=	sysutils
MASTER_SITES=	http://goodies.xfce.org/releases/xfburn/

MAINTAINER=	fbsd@opal.com
COMMENT=	CD/DVD burning tool for Xfce

LIB_DEPENDS=	burn.23:${PORTSDIR}/devel/libburn \
		isofs.12:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	hal-device:${PORTSDIR}/sysutils/hal \
		cdrdao:${PORTSDIR}/sysutils/cdrdao

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=${PREFIX}/bin/msgfmt DATADIRNAME=share

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	intltool pkgconfig
USE_XFCE=	configenv libexo libgui

.include <bsd.port.mk>
