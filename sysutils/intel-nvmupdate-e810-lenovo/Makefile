PORTNAME=	nvmupdate
DISTVERSION=	4.90.1.3897.0
CATEGORIES=	sysutils
MASTER_SITES=	https://download.lenovo.com/servers/mig/2026/01/12/63999/:lenovo \
		https://downloadmirror.intel.com/923633/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-e810-lenovo
DISTFILES=	${LENOVO_DISTFILE}:lenovo \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Lenovo Intel E810 adapters
WWW=		https://datacentersupport.lenovo.com/us/en/downloads/ds578930

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
SUB_FILES=	nvmupdate-e810-lenovo
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

LENOVO_DISTFILE=	intc-lnvgy_fw_nic_net.e800-4.90-1.3897.0-ja0cn-0262_anyos_comp.zip
INTEL_DISTFILE=		E810_NVMUpdatePackage_v5_01_FreeBSD.tar.gz

INTEL_WRKSRC=		${WRKDIR}/E810/FreeBSDx64
LENOVO_WRKSRC=		${WRKDIR}/lenovo
LENOVO_NVM_WRKSRC=	${WRKDIR}/lenovo-nvm
NVMUPDATE_DIR=		intel-nvmupdate-e810-lenovo

INTEL_FILES=		Intel_Proprietary_License.pdf \
			Intel_firmware_license.txt file_license.txt license.pdf \
			license.txt
LENOVO_PAYLOADS=	intc-lnvgy_fw_nic_net.e800.fam001-4.90-1.3897.0-ja0cn-026_anyos_comp.uxz \
			intc-lnvgy_fw_nic_net.e800.fam002-4.90-1.3897.0-ja0cn-026_anyos_comp.uxz \
			intc-lnvgy_fw_nic_net.e800.fam003-4.90-1.3897.0-ja0cn-026_anyos_comp.uxz \
			intc-lnvgy_fw_nic_net.e800.fam004-4.90-1.3897.0-ja0cn-026_anyos_comp.uxz
LENOVO_METADATA_PREFIX=	intc-lnvgy_fw_nic_net.e800
LENOVO_METADATA_SUFFIX=	4.90-1.3897.0-ja0cn-0262_anyos_comp

post-extract:
	${MKDIR} ${LENOVO_WRKSRC} ${LENOVO_NVM_WRKSRC}
	${TAR} -xf ${DISTDIR}/${LENOVO_DISTFILE} -C ${LENOVO_WRKSRC}
.for f in ${LENOVO_PAYLOADS}
	${TAR} -xf ${LENOVO_WRKSRC}/payloads/${f} -C ${LENOVO_NVM_WRKSRC}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
.for f in ${INTEL_FILES}
	${INSTALL_DATA} ${INTEL_WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD ${FILESDIR}/nvmupdate.cfg \
		${FILESDIR}/source_manifest.txt \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_DATA} ${LENOVO_WRKSRC}/${LENOVO_METADATA_PREFIX}-${LENOVO_METADATA_SUFFIX}.txt \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/LenovoReadme.txt
	${INSTALL_DATA} ${LENOVO_WRKSRC}/${LENOVO_METADATA_PREFIX}-${LENOVO_METADATA_SUFFIX}.chg \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/LenovoChg.chg
.for n in 001 002 003 004
	${INSTALL_DATA} ${LENOVO_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam${n}-${LENOVO_METADATA_SUFFIX}_inventory.json \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/inventory-fam${n}.json
	${INSTALL_DATA} ${LENOVO_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam${n}-${LENOVO_METADATA_SUFFIX}_signature.json \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/signature-fam${n}.json
.endfor
	${INSTALL_DATA} ${LENOVO_NVM_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam001-4.90-1.3897.0-ja0cn-026_anyos_comp.pldm \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/4002-AF-80021365.bin
	${INSTALL_DATA} ${LENOVO_NVM_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam002-4.90-1.3897.0-ja0cn-026_anyos_comp.pldm \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/4003-80021362.bin
	${INSTALL_DATA} ${LENOVO_NVM_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam003-4.90-1.3897.0-ja0cn-026_anyos_comp.pldm \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/4010-80021364.bin
	${INSTALL_DATA} ${LENOVO_NVM_WRKSRC}/${LENOVO_METADATA_PREFIX}.fam004-4.90-1.3897.0-ja0cn-026_anyos_comp.pldm \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/4013-80021363.bin
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-e810-lenovo \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
