PORTNAME=	data
PORTVERSION=	20221002
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/amd-ucode/
PKGNAMEPREFIX=	devcpu-
PKGNAMESUFFIX=	-amd
DISTFILES=	microcode_amd.bin?id=${_REV} \
		microcode_amd_fam15h.bin?id=${_REV} \
		microcode_amd_fam16h.bin?id=${_REV} \
		microcode_amd_fam17h.bin?id=${_REV} \
		microcode_amd_fam19h.bin?id=${_REV}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	AMD CPUs microcode updates

LICENSE=	EULA
LICENSE_NAME=	Advanced Micro Devices License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.amd-ucode
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/cpucontrol
NO_WRKSUBDIR=	yes
PLIST_FILES=	${DISTFILES:S/^/${DATADIR}\//g:C/\?.*//}

_REV=		fdf1a65258522edf18a0a1768fbafa61ed07e598

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/${f:C/\?.*//}
.endfor

.include <bsd.port.mk>
