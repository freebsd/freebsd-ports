# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Full-featured exFAT FS implementation as a FUSE module

LICENSE=	GPLv2+ MSPAT
LICENSE_COMB=	multi
LICENSE_NAME_MSPAT=	Microsoft exFAT Patent License
LICENSE_TEXT_MSPAT=	It is important to note that open source and other publicly \
			available implementations of exFAT do not include a patent \
			license from Microsoft. A license is required in order to \
			implement exFAT and use it in a product or device. \
	https://www.microsoft.com/en-us/legal/intellectualproperty/mtl/exfat-licensing.aspx
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_PERMS_MSPAT=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LIB_DEPENDS=	libublio.so:devel/libublio

USES=		autoreconf fuse localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	relan
GNU_CONFIGURE=	yes
MAKE_ARGS=	SUBDIRS="libexfat fuse"

PLIST_FILES=	sbin/mount.exfat-fuse sbin/mount.exfat man/man8/mount.exfat-fuse.8.gz

.include <bsd.port.mk>
