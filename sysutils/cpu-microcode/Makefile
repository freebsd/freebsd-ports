PORTNAME=	microcode
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	cpu-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Meta-package for CPU microcode updates

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	/boot/firmware/amd-ucode.bin:sysutils/cpu-microcode-amd \
		/boot/firmware/intel-ucode.bin:sysutils/cpu-microcode-intel

USES=		metaport

.include <bsd.port.mk>
