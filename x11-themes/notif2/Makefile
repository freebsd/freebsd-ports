# New ports collection makefile for:	notif2
# Date Created:				31 August 2001
# Whom:				 	Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	notif2
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	notif210
DISTNAME=	notif210-${GTKVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Notif2 GTK theme engine following the new Motif look and feel

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

GTKVERSION=	1.2
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
