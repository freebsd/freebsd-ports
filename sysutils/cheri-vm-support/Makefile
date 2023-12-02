PORTNAME=	cheri-vm-support
PORTVERSION=	20231201
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT=	Meta-port for CHERI virtual machine support.
WWW=		https://cheribsd.org/

USES=		metaport

ONLY_FOR_ARCHS=		aarch64c
ONLY_FOR_ARCHS_REASON=	assumes arm64 bhyve and no need for non-purecap

RUN_DEPENDS=	${LOCALBASE}/share/u-boot/u-boot-bhyve-arm64/u-boot.bin:sysutils/u-boot-bhyve-arm64

.include <bsd.port.mk>
