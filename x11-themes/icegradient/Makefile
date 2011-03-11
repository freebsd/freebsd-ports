# New ports collection makefile for:	icegradient
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/icegradient/Makefile,v 1.1 2006/07/20 11:38:25 ahze Exp $

PORTNAME=	icegradient
PORTVERSION=	200012290259
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	ftp://ftp.themes.org/pub/themes/gtk/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	IceGradient-1.2.x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ gradient theme engine based on ThinIce

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-0.0.5

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
