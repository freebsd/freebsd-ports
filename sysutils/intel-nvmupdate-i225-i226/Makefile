PORTNAME=	nvmupdate
DISTVERSION=	20260904
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/923640/:intel \
		https://people.freebsd.org/~kbowling/distfiles/:i225
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-i225-i226
DISTFILES=	E610_NVMUpdatePackage_v1_61_FreeBSD.tar.gz:intel \
		I225_NVMUpdatePackage_v1_00_Linux.tar.gz:i225

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Intel I225 and I226 Ethernet controllers
WWW=		https://github.com/BillyCurtis/Intel-I226-V-NVM-Firmware \
		https://www.intel.com/content/www/us/en/download/15084/intel-ethernet-adapter-complete-driver-pack.html

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

USE_GITHUB=	yes
GH_ACCOUNT=	BillyCurtis
GH_PROJECT=	Intel-I226-V-NVM-Firmware
GH_TAGNAME=	5fb02f3128f894fdeb47bea6450af872fb85ff45

NO_ARCH=	yes
NO_ARCH_IGNORE=	nvmupdate64e
NO_BUILD=	yes

SUB_FILES=	nvmupdate-i225-i226 pkg-message
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

INTEL_WRKSRC=	${WRKDIR}/E610/FreeBSDx64
I225_WRKSRC=	${WRKDIR}/I225/Linux_x64
NVMUPDATE_DIR=	intel-nvmupdate-i225-i226

CONFIG_FILES=	nvmupdate-i226-it-1mb.cfg nvmupdate-i226-it-2mb.cfg \
		nvmupdate-i226-lm-1mb.cfg nvmupdate-i226-lm-2mb.cfg \
		nvmupdate.cfg
INTEL_FILES=	Intel_Proprietary_License.pdf Intel_firmware_license.txt \
		file_license.txt license.pdf license.txt
I225_FILES=	FoxPond1_I225_15F2_2MB_1p94_800003BB.bin \
		Foxpond1_I225_15F2_LM_1MB_1p94_800003BC.bin \
		Foxpond_Map_File_v01.txt
NVM_FILES=	I225-V/1.89/FXVL_15F3_V_1MB_1.89.bin \
		I225-V/1.89/FXVL_15F3_V_2MB_1.89.bin \
		I226-V/2.32/FXVL_125B_LM_1MB_2.32.bin \
		I226-V/2.32/FXVL_125B_LM_2MB_2.32.bin \
		I226-V/2.32/FXVL_125C_V_1MB_2.32.bin \
		I226-V/2.32/FXVL_125C_V_2MB_2.32.bin \
		I226-V/2.32/FXVL_125D_IT_1MB_2.32.bin \
		I226-V/2.32/FXVL_125D_IT_2MB_2.32.bin
PORT_FILES=	README.FreeBSD source_manifest.txt version.txt

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
.for f in ${CONFIG_FILES} ${PORT_FILES}
	${INSTALL_DATA} ${FILESDIR}/${f} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
.for f in ${INTEL_FILES}
	${INSTALL_DATA} ${INTEL_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
.for f in ${I225_FILES}
	${INSTALL_DATA} ${I225_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
.for f in ${NVM_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/README.mirror
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-i225-i226 \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
