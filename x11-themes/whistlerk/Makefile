# New ports collection makefile for:	WhistlerK
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/whistlerk/Makefile,v 1.1 2006/07/20 11:38:27 ahze Exp $

PORTNAME=	WhistlerK
PORTVERSION=	200010142358
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	whistlerk
DISTNAME=	whistlerk-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK theme engine inspired by the Windows Whistler

WRKSRC=		${WRKDIR}/gtk-theme-WhistlerK

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/ltconfig

.include <bsd.port.mk>
