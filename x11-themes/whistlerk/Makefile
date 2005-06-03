# New ports collection makefile for:	WhistlerK
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WhistlerK
PORTVERSION=	200010142358
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	whistlerk
DISTNAME=	whistlerk-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine inspired by the Windows Whistler

WRKSRC=		${WRKDIR}/gtk-theme-WhistlerK

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
