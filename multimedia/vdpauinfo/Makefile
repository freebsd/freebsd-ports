# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	vdpauinfo
PORTVERSION=	0.1
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	A tool to query VDPAU capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvdpau.so:${PORTSDIR}/multimedia/libvdpau

USES=		pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
