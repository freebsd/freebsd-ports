# New ports collection makefile for:	gtk-Mac2-theme
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-Mac2-theme
PORTVERSION=	200003050858
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	mac2
DISTNAME=	mac2-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ engine theme based on the look of MacOS

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
