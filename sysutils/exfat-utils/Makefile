# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.7
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-utils

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Utilities to create, check, label and dump exFAT filesystem

LICENSE=	GPLv2+ MSPAT
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_NAME_MSPAT=	Microsoft exFAT Patent License
LICENSE_TEXT_MSPAT=	It is important to note that open source and other publicly \
			available implementations of exFAT do not include a patent \
			license from Microsoft. A license is required in order to \
			implement exFAT and use it in a product or device. \
	https://www.microsoft.com/en-us/legal/intellectualproperty/mtl/exfat-licensing.aspx
LICENSE_PERMS_MSPAT=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LIB_DEPENDS=	libublio.so:devel/libublio

USE_GITHUB=	yes
GH_ACCOUNT=	relan

USES=		autoreconf localbase pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/exfatlabel sbin/dumpexfat sbin/exfatfsck sbin/mkexfatfs \
		sbin/fsck.exfat sbin/mkfs.exfat \
		man/man8/exfatlabel.8.gz man/man8/mkexfatfs.8.gz man/man8/exfatfsck.8.gz \
		man/man8/dumpexfat.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/fuse/d' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's/ fuse//' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
