# New ports collection makefile for:	gtkstep-pastel
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkstep-pastel
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	gtksteppastel
DISTNAME=	gtksteppastel-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme engine based on GtkStep to make GTK+ look nicier

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
