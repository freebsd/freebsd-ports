# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	vdpauinfo
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tool to query VDPAU capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

USES=		pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
