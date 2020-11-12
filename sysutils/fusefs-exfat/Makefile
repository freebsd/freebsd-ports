# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Full-featured exFAT FS implementation as a FUSE module

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio

USES=		autoreconf fuse localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	relan
GNU_CONFIGURE=	yes
MAKE_ARGS=	SUBDIRS="libexfat fuse"

PLIST_FILES=	sbin/mount.exfat-fuse sbin/mount.exfat man/man8/mount.exfat-fuse.8.gz

.include <bsd.port.mk>
