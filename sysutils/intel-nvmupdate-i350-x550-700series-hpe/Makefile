PORTNAME=	nvmupdate
DISTVERSION=	1.37.0
CATEGORIES=	sysutils
MASTER_SITES=	https://downloads.linux.hpe.com/SDR/repo/fwpp-gen10/2026.07.00.00/:hpe \
		https://downloadmirror.intel.com/920687/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-i350-x550-700series-hpe
DISTFILES=	${HPE_DISTFILE}:hpe \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for HPE Intel I350/X550/700 Series adapters
WWW=		https://downloads.linux.hpe.com/SDR/project/fwpp-gen10/

LICENSE=	IFL IPL
LICENSE_COMB=	multi

LICENSE_NAME_IFL=	Intel Firmware License
LICENSE_NAME_IPL=	Intel Proprietary License
LICENSE_FILE_IFL=	${INTEL_WRKSRC}/Intel_firmware_license.txt
LICENSE_FILE_IPL=	${INTEL_WRKSRC}/license.txt
LICENSE_PERMS_IFL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

IGNORE_DragonFly=	FreeBSD binary port
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

NO_ARCH=	yes
NO_ARCH_IGNORE=	nvmupdate64e
NO_BUILD=	yes
SUB_FILES=	nvmupdate-i350-x550-700series-hpe
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

HPE_DISTFILE=	firmware-nic-intel-${DISTVERSION}-1.1.x86_64.rpm
INTEL_DISTFILE=	700Series_NVMUpdatePackage_v9_57_FreeBSD.tar.gz

INTEL_WRKSRC=		${WRKDIR}/700Series/FreeBSDx64
HPE_EXTRACT_ROOT=	${WRKDIR}/hpe
HPE_WRKSRC=		${HPE_EXTRACT_ROOT}/usr/lib/x86_64-linux-gnu/firmware-nic-intel-${DISTVERSION}-1.1/nic_fw
NVMUPDATE_DIR=		intel-nvmupdate-i350-x550-700series-hpe

INTEL_FILES=	Intel_Proprietary_License.pdf Intel_firmware_license.txt \
		file_license.txt license.pdf license.txt

post-extract:
	${MKDIR} ${HPE_EXTRACT_ROOT}
	${TAR} -xf ${DISTDIR}/${HPE_DISTFILE} -C ${HPE_EXTRACT_ROOT}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	cd ${HPE_WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR} "! -name nvmupdate.sh"
.for f in ${INTEL_FILES}
	${INSTALL_DATA} ${INTEL_WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-i350-x550-700series-hpe \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
