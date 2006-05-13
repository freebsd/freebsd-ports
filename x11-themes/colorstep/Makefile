# New ports collection makefile for:	colorstep
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colorstep
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	colorstep
DISTNAME=	${PORTNAME}-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A theme engine based on GtkStep and Step-pastel

WRKSRC=		${WRKDIR}/${PORTNAME}-0.6

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:15

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
