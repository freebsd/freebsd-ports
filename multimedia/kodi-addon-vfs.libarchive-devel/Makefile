# $FreeBSD$

PORTNAME=	vfs.libarchive
DISTVERSION=	1.0.5
DISTVERSIONSUFFIX=	-Leia
PORTREVISION=	3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	VFS addon for Kodi to access archives directly

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20191216:multimedia/kodi-devel
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2
RUN_DEPENDS=	kodi-devel>=19.0.a20191216:multimedia/kodi-devel

USES=		cmake libarchive ssl
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
