# $FreeBSD$

PORTNAME=		ntfs-compression
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0
CATEGORIES=		sysutils
PKGNAMEPREFIX=		fusefs-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	NTFS-3G plugin for reading XPRESS or LZX compressed files

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libntfs-3g.so:sysutils/fusefs-ntfs

USES=		fuse pkgconfig libtool autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	ebiggers
GH_PROJECT=	ntfs-3g-system-compression

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/ntfs-3g/ntfs-plugin-80000017.so

.include <bsd.port.mk>
