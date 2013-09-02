# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	vdpauinfo
PORTVERSION=	0.0.6
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freedesktop.org/~aplattner/vdpau/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to query VDPAU capabilities

LIB_DEPENDS=	vdpau.1:${PORTSDIR}/multimedia/libvdpau

USES=		pkgconfig
GNU_CONFIGURE=	yes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
