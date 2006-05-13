# New ports collection makefile for:	gtk-flat-theme
# Date Created:				31 October 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-flat-theme
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	flat
DISTNAME=	flat-1.2.x

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ theme engine which gives GTK+ a flattened appearance

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
