# ex:ts=8
# Ports collection makefile for:	libyahoo2
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libyahoo2
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library that handles the new Yahoo! Messenger protocol

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GNOME=	gnomehack glib20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
