# New ports collection makefile for:	libcroco
# Date created:				08 July 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcroco
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CSS2 parsing library

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack libgnomeui
CONFIGURE_ARGS=	--enable-layeng=yes \
		--enable-seleng=yes

MAN1=		croco-config.1 csslint.1

.include <bsd.port.mk>
