# New ports collection makefile for:	thinice
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	thinice
PORTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	thinice
DISTNAME=	thinice-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clean-looking GTK Theme Engine

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-theme-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
