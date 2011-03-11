# New ports collection makefile for:	engradient
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-themes/engradient/Makefile,v 1.1 2006/10/04 11:46:56 ahze Exp $

PORTNAME=	engradient
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	engradient
DISTNAME=	${PORTNAME}-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ engine-gradient theme based off of the IceGradient theme

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-${PORTVERSION}

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
