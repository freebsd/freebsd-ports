# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	exfat-utils
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Utilities to create, check, label and dump exFAT filesystem

LICENSE=	Microsoft-exFAT
LICENSE_NAME=	Microsoft exFAT License
LICENSE_TEXT=	Requires license from Microsoft, please see \
		http://www.microsoft.com/en-us/legal/intellectualproperty/IPLicensing/Programs/exFATFileSystem.aspx
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

LIB_DEPENDS=	libublio.so:devel/libublio

PROJECTHOST=	exfat

USES=		scons

PLIST_FILES=	sbin/exfatlabel sbin/dumpexfat sbin/exfatfsck sbin/mkexfatfs \
		man/man8/exfatlabel.8.gz man/man8/mkexfatfs.8.gz man/man8/exfatfsck.8.gz \
		man/man8/dumpexfat.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/label/exfatlabel ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/dump/dumpexfat ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/fsck/exfatfsck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mkfs/mkexfatfs ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/label/exfatlabel.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/mkfs/mkexfatfs.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/dump/dumpexfat.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/fsck/exfatfsck.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/SConstruct

.include <bsd.port.mk>
