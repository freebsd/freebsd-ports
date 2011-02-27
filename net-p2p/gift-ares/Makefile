# New ports collection makefile for:	giFT-Ares
# Date created:				2006-10-10
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	giFT-Ares
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	gift-ares
DISTNAME=	gift-ares-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	giFT plugin for the Ares peer-to-peer filesharing network

LIB_DEPENDS=	gift.0:${PORTSDIR}/net-p2p/gift

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig

DEPRECATED=	development has ceased; does not work
EXPIRATION_DATE=	2011-04-11

.include <bsd.port.mk>
