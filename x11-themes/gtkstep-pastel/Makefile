# New ports collection makefile for:	gtkstep-pastel
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gtkstep-pastel/Makefile,v 1.1 2006/07/20 11:38:25 ahze Exp $

PORTNAME=	gtkstep-pastel
PORTVERSION=	0.10.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	gtksteppastel
DISTNAME=	gtksteppastel-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Theme engine based on GtkStep to make GTK+ look nicier

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
