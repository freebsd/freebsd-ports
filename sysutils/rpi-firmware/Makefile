# $FreeBSD$

PORTNAME=	rpi-firmware
PORTVERSION=	1.20210303.g20210303
CATEGORIES=	sysutils

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	Firmware for RaspberryPi Single Board Computer

LICENSE=	BROADCOM
LICENSE_NAME=	Broadcom Corporation
LICENSE_FILE=	${WRKSRC}/boot/LICENCE.broadcom
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

BUILD_DEPENDS=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc

USE_GITHUB=	yes

GH_ACCOUNT=	raspberrypi gonzoua:pscimon
GH_PROJECT=	firmware rpi3-psci-monitor:pscimon
FW_TAG=		fcf8d2f
PSCI_TAG=	558620c
GH_TAGNAME=	${FW_TAG} ${PSCI_TAG}:pscimon

BUILD_WRKSRC=	${WRKSRC_pscimon}
INSTALL_DIR=	${PREFIX}/share/${PORTNAME}

CONFIG_TXT_FILES=	config.txt \
			config_rpi_0_w.txt \
			config_rpi3.txt \
			config_rpi3_edk2.txt \
			config_rpi4.txt \
			config_arm64.txt

do-patch:
.for i in ${CONFIG_TXT_FILES}
	${CP} ${FILESDIR}/${i} ${WRKSRC}/boot/
.endfor

post-patch:
	${RM} ${WRKSRC}/boot/kernel.img
	${RM} ${WRKSRC}/boot/kernel7.img
	${RM} ${WRKSRC}/boot/kernel7l.img
	${RM} ${WRKSRC}/boot/kernel8.img

do-install:
	${MKDIR} ${STAGEDIR}/${INSTALL_DIR}
	cd ${WRKSRC}/boot && ${COPYTREE_SHARE} . ${STAGEDIR}/${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKSRC_pscimon}/armstub8.bin \
	    ${WRKSRC_pscimon}/armstub8-gic.bin ${STAGEDIR}/${INSTALL_DIR}/

.include <bsd.port.mk>
