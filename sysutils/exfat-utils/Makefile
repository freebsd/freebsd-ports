# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	exfat-utils
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Utilities to create, check, label and dump exFAT filesystem

LICENSE=	GPLv2

LIB_DEPENDS=	ublio:${PORTSDIR}/devel/libublio

PROJECTHOST=	exfat

USE_SCONS=	yes

MAN8=		exfatlabel.8 mkexfatfs.8 dumpexfat.8 exfatfsck.8
PLIST_FILES=	sbin/exfatlabel sbin/dumpexfat sbin/exfatfsck sbin/mkexfatfs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/label/exfatlabel ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/dump/dumpexfat ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/fsck/exfatfsck ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mkfs/mkexfatfs ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/label/exfatlabel.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/mkfs/mkexfatfs.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/dump/dumpexfat.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/fsck/exfatfsck.8 ${MAN8PREFIX}/man/man8

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|' ${WRKSRC}/SConstruct

.include <bsd.port.mk>
