# New ports collection makefile for:	gtkstep
# Date Created:				7 nov 98
# Whom:				 	Gilad Rom
#
# $FreeBSD$
#

PORTNAME=	gtkstep
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/gtk-engines-gtkstep
DISTNAME=	gtk-engines-${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A theme module to make GTK+ look like the NeXTSTEP(tm) interface

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
