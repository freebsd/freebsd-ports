# $FreeBSD$

PORTNAME=	urtwn-firmware
PORTVERSION=	${FWVERSION}
CATEGORIES=	net kld
MASTER_SITES=	http://firmware.openbsd.org/firmware-dist/
PKGNAMESUFFIX=	-kmod
DISTNAME=	${FWNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Realtek RTL8188CU/RTL8192CU firmware kernel module

DRIVERNAME=	urtwn
FWVERSION?=	1.1
FWNAME=		${DRIVERNAME}-${FWVERSION}

WRKSRC=		${WRKDIR}
KMODDIR=	/boot/modules
KMODVERSION=	${FWVERSION:C/^(...)$/\1.0/:S/.//g}
PLIST_SUB=	DRIVERNAME="${DRIVERNAME}" \
		KMODDIR="${KMODDIR}"
CFLAGS+=	-D_KERNEL

NO_PACKAGE=	This is a modified version of a restricted firmware

.include <bsd.port.pre.mk>

post-patch:
	@${MKDIR} ${WRKSRC}/${DRIVERNAME}
	@${ECHO_CMD} "KMOD= ${DRIVERNAME}" > ${WRKSRC}/${DRIVERNAME}/Makefile
.for firms in urtwn-rtl8192cfwT urtwn-rtl8192cfwU
	@${MV} ${WRKSRC}/${firms} ${WRKSRC}/${DRIVERNAME}/${firms}
	@${ECHO_CMD} "FIRMWS+= ${firms}:${firms}:${KMODVERSION}" >> \
		${WRKSRC}/${DRIVERNAME}/Makefile
.endfor
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> \
		${WRKSRC}/${DRIVERNAME}/Makefile

do-build:
	@cd ${WRKSRC}/${DRIVERNAME}; ${SETENV} KMODDIR="${KMODDIR}" make all

do-install:
	@cd ${WRKSRC}/${DRIVERNAME}; ${SETENV} KMODDIR="${KMODDIR}" make install

.include <bsd.port.post.mk>
