# Created by: cpm <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	malo-firmware
PORTVERSION=	${FWVERSION}
CATEGORIES=	net
MASTER_SITES=	http://fbsd.es/~cpm/freebsd/project/malo/
PKGNAMESUFFIX=	-kmod
DISTNAME=	${FWNAME}

MAINTAINER=	cpm@fbsd.es
COMMENT=	Marvell Libertas 88W8335 IEEE 802.11b/g Firmware Kernel Module

LICENSE= 	BSD3CLAUSE

FWNAME=		malo-fw-${FWVERSION}
FWVERSION=	3.0.0.39

USES=		kmod
DRIVERNAME=	malofw
FIRMS=		malo8335-h:malo8335-m
WRKSRC=		${WRKDIR}
KMODVERSION=	${FWVERSION:C/^(...)$/\1.0/:S/.//g}
PLIST_SUB=	DRIVERNAME="${DRIVERNAME}" \
		KMODDIR="${KMODDIR}"
CFLAGS+=	-D_KERNEL

NO_PACKAGE=	This is a modified version of a restricted firmware

.include <bsd.port.pre.mk>

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

do-build:
	(cd ${WRKSRC}/${DRIVERNAME} && \
	 ${SETENV} KMODDIR="${KMODDIR}" ${MAKE_CMD} all)

do-install:
	${MKDIR} ${STAGEDIR}${KMODDIR}
	cd ${WRKSRC}/${DRIVERNAME}; ${SETENV} KMODDIR="${STAGEDIR}${KMODDIR}" make ${INSTALL}
	${STRIP_CMD} --strip-unneeded ${STAGEDIR}${KMODDIR}/${DRIVERNAME}.ko

.include <bsd.port.post.mk>
