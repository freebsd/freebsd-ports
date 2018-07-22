# $FreeBSD$

PORTNAME=	rpi-firmware
PORTVERSION=	1.20180619
CATEGORIES=	sysutils

MAINTAINER=	uboot@freebsd.org
COMMENT=	Firmware for RaspberryPi Single Board Computer

LICENSE=	BROADCOM
LICENSE_NAME=	Broadcom Corporation
LICENSE_FILE=	${WRKSRC}/boot/LICENCE.broadcom
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USE_GITHUB=	yes
GH_ACCOUNT=	raspberrypi gonzoua:pscimon
GH_PROJECT=	firmware rpi3-psci-monitor:pscimon
PSCI_TAG=	2b8890a
GH_TAGNAME=	${PSCI_TAG}:pscimon
PSCI_MONITOR=	rpi3-psci-monitor-${PSCI_TAG}
PSCI_DIR=	${WRKDIR}/${PSCI_MONITOR}

BUILD_WRKSRC=	${PSCI_DIR}
INSTALL_DIR=	${PREFIX}/share/${PORTNAME}

CONFIG_TXT_FILES=	config.txt config_rpi_0_w.txt config_rpi3.txt

do-patch:
.for i in ${CONFIG_TXT_FILES}
	${CP} ${FILESDIR}/${i} ${WRKSRC}/boot/
.endfor

post-patch:
	${RM} ${WRKSRC}/boot/kernel.img
	${RM} ${WRKSRC}/boot/kernel7.img

do-install:
	${MKDIR} ${STAGEDIR}/${INSTALL_DIR}
	cd ${WRKSRC}/boot && ${COPYTREE_SHARE} . ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${PSCI_DIR}/armstub8.bin ${STAGEDIR}/${INSTALL_DIR}/

.include <bsd.port.mk>
