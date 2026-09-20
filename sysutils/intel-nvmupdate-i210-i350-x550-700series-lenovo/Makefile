PORTNAME=	nvmupdate
DISTVERSION=	9.55.6.50.1.3866.0.4
CATEGORIES=	sysutils
MASTER_SITES=	https://download.lenovo.com/servers/mig/2026/01/12/63978/:lenovo \
		https://downloadmirror.intel.com/923633/:intel
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-i210-i350-x550-700series-lenovo
DISTFILES=	${LENOVO_DISTFILE}:lenovo \
		${INTEL_DISTFILE}:intel
EXTRACT_ONLY=	${INTEL_DISTFILE}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM update utility for Lenovo Intel I210/I350/X550/700 Series adapters
WWW=		https://datacentersupport.lenovo.com/us/en/downloads/ds578913

LICENSE=	IFL IPL
LICENSE_COMB=	multi

LICENSE_NAME_IFL=	Intel Firmware License
LICENSE_NAME_IPL=	Intel Proprietary License
LICENSE_FILE_IFL=	${LENOVO_WRKSRC}/Intel_firmware_license.txt
LICENSE_FILE_IPL=	${LENOVO_WRKSRC}/license.txt
LICENSE_PERMS_IFL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

IGNORE_DragonFly=	FreeBSD binary port
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

NO_ARCH=	yes
NO_ARCH_IGNORE=	nvmupdate64e
NO_BUILD=	yes
SUB_FILES=	nvmupdate-i210-i350-x550-700series-lenovo
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}

LENOVO_DISTFILE=	intc-lnvgy_fw_nic_net-9.55-6.50-1.3866.0-4_linux_x86-64.bin
INTEL_DISTFILE=		E810_NVMUpdatePackage_v5_01_FreeBSD.tar.gz

INTEL_WRKSRC=		${WRKDIR}/E810/FreeBSDx64
LENOVO_EXTRACT_ROOT=	${WRKDIR}/lenovo
LENOVO_WRKSRC=		${LENOVO_EXTRACT_ROOT}/image
NVMUPDATE_DIR=		intel-nvmupdate-i210-i350-x550-700series-lenovo

post-extract:
	${MKDIR} ${LENOVO_EXTRACT_ROOT}
	${TAR} -xf ${DISTDIR}/${LENOVO_DISTFILE} -C ${LENOVO_EXTRACT_ROOT}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	cd ${LENOVO_WRKSRC} && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR} \
		"! -name nvmupdate64e ! -name install-nvm-linux-x64-updated.sh"
	${INSTALL_PROGRAM} ${INTEL_WRKSRC}/nvmupdate64e \
		${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-i210-i350-x550-700series-lenovo \
		${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
