# New ports collection makefile for:	gnome-look
# Date Created:				10 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gnome-look/Makefile,v 1.1 2006/07/19 19:56:14 ahze Exp $

PORTNAME=	gnome-look
PORTVERSION=	0.1.3
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine designed to look nice with the GNOME desktop

USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
