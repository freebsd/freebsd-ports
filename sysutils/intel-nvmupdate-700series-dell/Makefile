PORTNAME=	nvmupdate
DISTVERSION=	25.0.4
CATEGORIES=	sysutils
MASTER_SITES=	https://dl.dell.com/FOLDER14205970M/2/:dell \
		https://downloadmirror.intel.com/920687/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-700series-dell
DISTFILES=	${DELL_DISTFILE}:dell \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Dell Intel Ethernet 700 Series adapters
WWW=		https://www.dell.com/support/home/en-us/drivers/driversdetails?driverid=PJDHV

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
SUB_FILES=	nvmupdate-700series-dell
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

DELL_DISTFILE=	Network_Firmware_PJDHV_LN_25.0.4_A00.BIN
INTEL_DISTFILE=	700Series_NVMUpdatePackage_v9_57_FreeBSD.tar.gz

INTEL_WRKSRC=	${WRKDIR}/700Series/FreeBSDx64
DELL_WRKSRC=	${WRKDIR}/dell
NVMUPDATE_DIR=	intel-nvmupdate-700series-dell

INTEL_FILES=	Intel_Proprietary_License.pdf Intel_firmware_license.txt \
		file_license.txt license.pdf license.txt
DELL_FILES=	08XJ7.txt 68M95.txt 6VDPG.txt 6VDPG_1G.txt BootIMG.FLB CFQP.txt \
		DDJKY.txt DX69G.txt KF46X.txt Version.txt XD56X.txt Y348Y.txt \
		Y5M7N.txt demere_map.txt harbor_map.txt kerby_map.txt \
		nut_msg.txt nvminv.cfg nvmupdate.cfg vpd.txt vpd_modified.txt

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
	${INSTALL_DATA} ${DELL_WRKSRC}/l64/license.pdf \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/license-dell.pdf
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-700series-dell \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
