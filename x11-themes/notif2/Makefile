# New ports collection makefile for:	notif2
# Date Created:				31 August 2001
# Whom:				 	Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/notif2/Makefile,v 1.1 2006/07/20 11:38:26 ahze Exp $

PORTNAME=	notif2
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	notif210
DISTNAME=	notif210-${GTKVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Notif2 GTK theme engine following the new Motif look and feel

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

GTKVERSION=	1.2

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
