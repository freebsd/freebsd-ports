# $FreeBSD$

PORTNAME=	rpi-firmware
PORTVERSION=	1.20170811
CATEGORIES=	sysutils

MAINTAINER=	manu@freebsd.org
COMMENT=	Firmware for RaspberryPi Single Board Computer

LICENSE=	BROADCOM
LICENSE_NAME=	Broadcom Corporation
LICENSE_FILE=	${WRKSRC}/boot/LICENCE.broadcom
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	raspberrypi
GH_PROJECT=	firmware

NO_BUILD=	yes

INSTALL_DIR=	${PREFIX}/share/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}/${INSTALL_DIR}
	${INSTALL_DATA} ${LICENSE_FILE} ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/bootcode.bin ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/fixup_cd.dat ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/fixup_db.dat ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/fixup_x.dat ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/fixup.dat ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/start_cd.elf ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/start_db.elf ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/start_x.elf ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/start.elf ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC}/boot/config.txt ${STAGEDIR}/${INSTALL_DIR}/

.include <bsd.port.mk>
