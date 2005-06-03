# New ports collection makefile for:	gtkbe
# Date Created:				6 July 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkbe
PORTVERSION=	200007091019
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	gtkbe
DISTNAME=	gtkbe-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BeOS look-alike GTK+ theme engine

WRKSRC=		${WRKDIR}/GTKBeEngine

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
