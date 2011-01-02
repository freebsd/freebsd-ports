# New ports collection makefile for:	vdpauinfo
# Date created:				2010-09-08
# Whom:					Anonymous <swell.k@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	vdpauinfo
PORTVERSION=	0.0.6
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	swell.k@gmail.com
COMMENT=	A tool to query VDPAU capabilities

LIB_DEPENDS=	vdpau.1:${PORTSDIR}/multimedia/libvdpau

GNU_CONFIGURE=	yes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
