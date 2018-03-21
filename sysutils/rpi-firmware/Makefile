# $FreeBSD$

PORTNAME=	rpi-firmware
PORTVERSION=	1.20171029
PORTREVISION=	1
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

do-patch:
	${CP} ${FILESDIR}/config.txt ${WRKSRC}/boot/

post-patch:
	${RM} ${WRKSRC}/boot/kernel.img
	${RM} ${WRKSRC}/boot/kernel7.img

do-install:
	${MKDIR} -p ${STAGEDIR}/${INSTALL_DIR}
	cd ${WRKSRC}/boot && ${COPYTREE_SHARE} . ${STAGEDIR}/${INSTALL_DIR}/

.include <bsd.port.mk>
