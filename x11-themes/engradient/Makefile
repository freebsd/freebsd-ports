# New ports collection makefile for:	engradient
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	engradient
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	engradient
DISTNAME=	${PORTNAME}-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ engine-gradient theme based off of the IceGradient theme

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
