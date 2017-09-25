# Created by: Carlos J Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grive2
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libyajl.so:devel/yajl

CONFLICTS_INSTALL=	grive-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	vitalif

USES=		cmake pkgconfig localbase

PLIST_FILES=	bin/grive \
		man/man1/grive.1.gz

.include <bsd.port.mk>
