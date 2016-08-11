# Created by: cpm <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	malo-firmware
PORTVERSION=	${FWVERSION}
CATEGORIES=	net
MASTER_SITES=	LOCAL/cpm
PKGNAMESUFFIX=	-kmod
DISTNAME=	${FWNAME}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Marvell Libertas 88W8335 IEEE 802.11b/g Firmware Kernel Module

FWNAME=		malo-fw-${FWVERSION}
FWVERSION=	3.0.0.39

USES=		kmod uidfix
DRIVERNAME=	malofw
FIRMS=		malo8335-h:malo8335-m
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/${DRIVERNAME}
INSTALL_WRKSRC=	${WRKSRC}/${DRIVERNAME}
KMODVERSION=	${FWVERSION:C/^(...)$/\1.0/:S/.//g}
PLIST_FILES=	${KMODDIR}/${DRIVERNAME}.ko
CFLAGS+=	-D_KERNEL

NO_PACKAGE=	This is a modified version of a restricted firmware

post-patch:
	${MKDIR} ${WRKSRC}/${DRIVERNAME}
	${MV} ${WRKSRC}/${FIRMS:C/:.*//} \
		${WRKSRC}/${DRIVERNAME}/${FIRMS:C/:.*//}
	${MV} ${WRKSRC}/${FIRMS:C/.*://} \
		${WRKSRC}/${DRIVERNAME}/${FIRMS:C/.*://}
	${ECHO_CMD} "KMOD= ${DRIVERNAME}" > ${WRKSRC}/${DRIVERNAME}/Makefile
	${ECHO_CMD} "FIRMWS= ${FIRMS:C/:.*//}:${FIRMS:C/:.*//}:${KMODVERSION} \\" >> \
		${WRKSRC}/${DRIVERNAME}/Makefile
	${ECHO_CMD} "	${FIRMS:C/.*://}:${FIRMS:C/.*://}:${KMODVERSION}" >> \
		${WRKSRC}/${DRIVERNAME}/Makefile
	${ECHO_CMD} ".include <bsd.kmod.mk>" >> \
		${WRKSRC}/${DRIVERNAME}/Makefile

.include <bsd.port.mk>
