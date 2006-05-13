# New ports collection makefile for:	icegradient
# Date Created:				21 August 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icegradient
PORTVERSION=	200012290259
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	ftp://ftp.themes.org/pub/themes/gtk/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sobomax
DISTNAME=	IceGradient-1.2.x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ gradient theme engine based on ThinIce

WRKSRC=		${WRKDIR}/gtk-${PORTNAME}-0.0.5

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
