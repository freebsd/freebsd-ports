PORTNAME=	nvmupdate
DISTVERSION=	2_00
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freebsd.org/~kbowling/distfiles/
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-i210
DISTNAME=	I210_NVMUpdatePackage_v${DISTVERSION}_FreeBSD

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	NVM Update Utility for Intel(R) Ethernet I210 Series
WWW=		https://www.intel.com/content/www/us/en/download/15084/intel-ethernet-adapter-complete-driver-pack.html

LICENSE=	IFL IPL
LICENSE_COMB=	multi

LICENSE_NAME_IFL=	Intel Firmware License
LICENSE_NAME_IPL=	Intel Proprietary License
LICENSE_FILE_IFL=	${WRKSRC}/Intel_firmware_license.txt
LICENSE_FILE_IPL=	${WRKSRC}/license.txt
LICENSE_PERMS_IFL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_IPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

IGNORE_DragonFly=	FreeBSD binary port
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

NO_ARCH=	yes
NO_ARCH_IGNORE=	nvmupdate64e
NO_BUILD=	yes

SUB_FILES=	nvmupdate-i210
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

WRKSRC=		${WRKDIR}/I210/FreeBSDx64

NVMUPDATE_DIR=	intel-nvmupdate-i210

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR} "! -name 'nvmupdate64e'"
	${INSTALL_PROGRAM} ${WRKSRC}/nvmupdate64e ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-i210 ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
