# New ports collection makefile for:	gnome-look
# Date Created:				10 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-look
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine designed to look nice with the GNOME desktop environment

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
