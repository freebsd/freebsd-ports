# New ports collection makefile for:	gtk-flat-theme
# Date Created:				31 October 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/gtk-flat-theme/Makefile,v 1.1 2006/07/19 19:56:17 ahze Exp $

PORTNAME=	gtk-flat-theme
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	flat
DISTNAME=	flat-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ theme engine which gives GTK+ a flattened appearance

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
