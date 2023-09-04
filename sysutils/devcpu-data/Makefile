PORTNAME=	data
PORTVERSION=	20230617
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	devcpu-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CPUs microcode updates (DEPRECATED)

DEPRECATED=	Use sysutils/cpu-microcode
EXPIRATION_DATE=	2023-12-31

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	${LOCALBASE}/share/cpucontrol/microcode_amd.bin:sysutils/cpu-microcode-amd \
		/boot/firmware/intel-ucode.bin:sysutils/cpu-microcode-intel

USES=		metaport

.include <bsd.port.mk>
