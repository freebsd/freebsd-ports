# Created by: Alex Samorukov <samm@freebsd.org>
# $FreeBSD$

PORTNAME=	exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-utils

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Utilities to create, check, label and dump exFAT filesystem

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio

USES=		autoreconf localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	relan
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/exfatlabel sbin/dumpexfat sbin/exfatfsck sbin/mkexfatfs \
		sbin/fsck.exfat sbin/mkfs.exfat \
		man/man8/exfatlabel.8.gz man/man8/mkexfatfs.8.gz man/man8/exfatfsck.8.gz \
		man/man8/dumpexfat.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/fuse/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/ fuse//' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
