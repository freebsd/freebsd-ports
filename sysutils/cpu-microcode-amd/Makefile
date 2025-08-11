PORTNAME=	microcode
PORTVERSION=	20250729
CATEGORIES=	sysutils
MASTER_SITES=	https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/plain/amd-ucode/
PKGNAMEPREFIX=	cpu-
PKGNAMESUFFIX=	-amd
DISTFILES=	microcode_amd.bin?id=${_REV} \
		microcode_amd_fam15h.bin?id=${_REV} \
		microcode_amd_fam16h.bin?id=${_REV} \
		microcode_amd_fam17h.bin?id=${_REV} \
		microcode_amd_fam19h.bin?id=${_REV} \
		microcode_amd_fam1ah.bin?id=${_REV}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	AMD CPU microcode updates

LICENSE=	EULA
LICENSE_NAME=	Advanced Micro Devices License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE.amd-ucode
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	${LOCALBASE}/etc/rc.d/microcode_update:sysutils/cpu-microcode-rc

DATADIR=	${PREFIX}/share/cpucontrol
FWDIR=		/boot/firmware

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes
PLIST_FILES=	${DISTFILES:S/^/${DATADIR}\//g:C/\?.*//} \
		${FWDIR}/amd-ucode.bin

_REV=		3768c184de68a85b9df6697e7f93a2f61de90a99

post-extract:
	${CAT} ${WRKSRC}/microcode_amd* > ${WRKSRC}/amd-ucode.bin

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${FWDIR}
	${INSTALL_DATA} ${WRKSRC}/amd-ucode.bin ${STAGEDIR}${FWDIR}/
.for f in ${DISTFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/${f:C/\?.*//}
.endfor

.include <bsd.port.mk>
