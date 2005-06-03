# New ports collection makefile for:	buffy
# Date Created:				13 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buffy
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	buffy02
DISTNAME=	buffy02-1.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine looking like SGI enhanced Motif (aka Roxy)

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
