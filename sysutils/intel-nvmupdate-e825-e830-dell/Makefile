PORTNAME=	nvmupdate
DISTVERSION=	30.5.0.57
CATEGORIES=	sysutils
MASTER_SITES=	https://dl.dell.com/FOLDER14838807M/1/:dell \
		https://downloadmirror.intel.com/923594/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-e825-e830-dell
DISTFILES=	${DELL_DISTFILE}:dell \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Dell Intel E825 and E830 adapters
WWW=		https://www.dell.com/support/home/en-us/drivers/driversdetails?driverid=69TRD

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
SUB_FILES=	nvmupdate-e825-e830-dell
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

DELL_DISTFILE=	XR8720T_Network_Firmware_69TRD_WN64_30.5.0.57_A00.EXE
INTEL_DISTFILE=	E830_E835_NVMUpdatePackage_v2_11_FreeBSD.tar.gz

INTEL_WRKSRC=	${WRKDIR}/E830_E835/FreeBSDx64
DELL_WRKSRC=	${WRKDIR}/dell
NVMUPDATE_DIR=	intel-nvmupdate-e825-e830-dell

INTEL_FILES=	Intel_Proprietary_License.pdf Intel_firmware_license.txt \
		file_license.txt license.pdf license.txt
DELL_FILES=	intel_version.txt nut_msg.txt nvminv.cfg nvmupdate.cfg
NVM_FILES=	carter_flat.bin GNRD_QSFP_0.bin GNRD_QSFP_1.bin \
		GNRD_QSFP_OEM_0.bin GNRD_QSFP_OEM_1.bin GNRD_SFP_0.bin \
		GNRD_SFP_1.bin GNRD_SFP_OEM_0.bin GNRD_SFP_OEM_1.bin

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
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-e825-e830-dell \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
