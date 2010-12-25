# New ports collection makefile for:   lxde-icon-theme
# Date created:                09/23/2010
# Whom:                        Kris Moore <kmoore@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	lxde-icon-theme
PORTVERSION=	0.0.1
CATEGORIES=	x11-themes
MASTER_SITES=	SF/lxde/LXDE%20Icon%20Theme/lxde-icon-theme-${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	LXDE Icon Theme

USE_BZIP2=	YES
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

DATADIR=	${PREFIX}/share/lxde
INSTALLS_ICONS=	YES

.include <bsd.port.mk>
