# New ports collection makefile for:	libcdio
# Date created:				2004-04-04
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	libcdio
PORTVERSION=	0.68
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	libcdio

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Compact Disc Input and Control Library

LIB_DEPENDS=	cddb.1:${PORTSDIR}/audio/libcddb

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget pkgconfig gnomehack
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

INFO=		libcdio

.include <bsd.port.mk>
