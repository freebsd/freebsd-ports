PORTNAME=	nvmupdate
DISTVERSION=	25.0.4
CATEGORIES=	sysutils
MASTER_SITES=	https://dl.dell.com/FOLDER14206109M/1/:dell \
		https://downloadmirror.intel.com/923633/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-e810-e823-dell
DISTFILES=	${DELL_DISTFILE}:dell \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Dell Intel E810 and E823 adapters
WWW=		https://www.dell.com/support/home/en-us/drivers/driversdetails?driverid=FCG2V

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

FETCH_ARGS+=	--user-agent=Mozilla/5.0
NO_ARCH=	yes
NO_ARCH_IGNORE=	nvmupdate64e
NO_BUILD=	yes
SUB_FILES=	nvmupdate-e810-e823-dell
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

DELL_DISTFILE=	Network_Firmware_FCG2V_LN_25.0.4_A00.BIN
INTEL_DISTFILE=	E810_NVMUpdatePackage_v5_01_FreeBSD.tar.gz

INTEL_WRKSRC=	${WRKDIR}/E810/FreeBSDx64
DELL_WRKSRC=	${WRKDIR}/dell
NVMUPDATE_DIR=	intel-nvmupdate-e810-e823-dell

INTEL_FILES=	Intel_Proprietary_License.pdf Intel_firmware_license.txt \
		file_license.txt license.pdf license.txt
DELL_FILES=	Version.txt nut_msg.txt nvminv.cfg nvmupdate.cfg
NVM_FILES=	aspen_flat_inj.bin chapman_beach_inj.bin \
		clifton_channel_inj.bin derrick_key_inj.bin \
		logan_beach-nognss_inj.bin logan_beach_inj.bin \
		meadow_flat_inj.bin outlander_soc_inj.bin salem_channel_inj.bin \
		tacoma_rapids_inj.bin westport_channel-nognss_inj.bin \
		westport_channel_inj.bin

post-extract:
	${MKDIR} ${DELL_WRKSRC}
	${TAR} -xf ${DISTDIR}/${DELL_DISTFILE} -C ${DELL_WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
.for f in ${INTEL_FILES}
	${INSTALL_DATA} ${INTEL_WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
.for f in ${DELL_FILES}
	${INSTALL_DATA} ${DELL_WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
.for f in ${NVM_FILES}
	${INSTALL_DATA} ${DELL_WRKSRC}/payload/${f} \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
	${INSTALL_DATA} ${DELL_WRKSRC}/l64/license.pdf \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/license-dell.pdf
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-e810-e823-dell \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
