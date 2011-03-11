# New ports collection makefile for:	gtkstep
# Date Created:				7 nov 98
# Whom:				 	Gilad Rom
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gtkstep/Makefile,v 1.1 2006/07/20 11:38:24 ahze Exp $

PORTNAME=	gtkstep
PORTVERSION=	2.2
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gtk-engines-gtkstep
DISTNAME=	gtk-engines-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A theme module to make GTK+ look like the NeXTSTEP(tm) interface

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
