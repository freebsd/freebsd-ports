PORTNAME=	exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-utils

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Utilities to create, check, label and dump exFAT filesystem
WWW=		https://github.com/relan/exfat

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio

USES=		autoreconf cpe localbase pkgconfig
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	relan
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/exfatlabel sbin/dumpexfat sbin/exfatfsck sbin/mkexfatfs \
		sbin/fsck.exfat sbin/mkfs.exfat sbin/exfatattrib \
		man/man8/exfatlabel.8.gz man/man8/mkexfatfs.8.gz man/man8/exfatfsck.8.gz \
		man/man8/dumpexfat.8.gz man/man8/exfatattrib.8.gz

.include <bsd.port.mk>
