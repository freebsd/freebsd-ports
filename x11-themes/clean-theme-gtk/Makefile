# New ports collection makefile for:	clean-theme-gtk
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/clean-theme-gtk/Makefile,v 1.1 2006/07/19 19:56:11 ahze Exp $

PORTNAME=	clean-theme-gtk
PORTVERSION=	1.2.x
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	clean___
DISTNAME=	clean___-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Clean GTK theme engine

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/gtk-clean-theme

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
