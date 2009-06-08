# New ports collection makefile for:	jnettop
# Date created:				5 June 2009
# Whom:					Ryan Steinmetz
#
# $FreeBSD$
#

PORTNAME=	jnettop
PORTVERSION=	0.13.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SFE/jnettop
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	rpsfa@rit.edu
COMMENT=	Traffic visualizer, similiar to nettop

MAN8=		jnettop.8

GNU_CONFIGURE=	yes
USE_GNOME=	glib20

CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.mk>
