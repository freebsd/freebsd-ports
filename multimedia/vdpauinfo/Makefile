# Created by: Anonymous <swell.k@gmail.com>
# $FreeBSD$

PORTNAME=	vdpauinfo
PORTVERSION=	1.4
CATEGORIES=	multimedia

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Tool to query VDPAU capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvdpau.so:multimedia/libvdpau

USES=		autoreconf pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	vdpau
GL_COMMIT=	3463ab40a89179e6e199575e8bee9c23ee027377
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/vdpauinfo

.include <bsd.port.mk>
