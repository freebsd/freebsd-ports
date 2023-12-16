PORTNAME=	ntfs-compression
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	NTFS-3G plugin for reading XPRESS or LZX compressed files
WWW=		https://github.com/ebiggers/ntfs-3g-system-compression

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libntfs-3g.so:sysutils/fusefs-ntfs

USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	ebiggers
GH_PROJECT=	ntfs-3g-system-compression

PLIST_FILES=	lib/ntfs-3g/ntfs-plugin-80000017.so

.include <bsd.port.mk>
