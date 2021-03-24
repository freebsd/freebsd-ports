# $FreeBSD$

PORTNAME=	bhyve-firmware
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Collection of Firmware for bhyve

RUN_DEPENDS=	uefi-edk2-bhyve>=0:sysutils/uefi-edk2-bhyve

USES=			metaport
OPTIONS_DEFINE=		CSM
OPTIONS_DEFAULT=	CSM
CSM_DESC=		Include firmware with Compatibility Support Module
CSM_RUN_DEPENDS=	uefi-edk2-bhyve-csm>=0:sysutils/uefi-edk2-bhyve-csm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSM}
DEPRECATED=	Uses EOL Python 2.7 via sysutils/uefi-edk2-bhyve
EXPIRATION_DATE=2021-06-23
.endif

.include <bsd.port.mk>
