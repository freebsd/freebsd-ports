PORTNAME=	nvmupdate
DISTVERSION=	9_20
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/769288/
PKGNAMEPREFIX=	intel-
PKGNAMESUFFIX=	-40g
DISTNAME=	700Series_NVMUpdatePackage_v${DISTVERSION}_FreeBSD

MAINTAINER=	freebsd@intel.com
COMMENT=	NVM Update Utility for Intel(R) 40G Ethernet Adapters
WWW=		https://downloadcenter.intel.com

LICENSE=		IFL IPL
LICENSE_COMB=		multi

IGNORE_DragonFly=	FreeBSD binary port
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64

LICENSE_NAME_IFL=	Intel Firmware License
LICENSE_FILE_IFL=	${WRKSRC}/Intel_firmware_license.txt
LICENSE_PERMS_IFL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LICENSE_NAME_IPL=	Intel Proprietary License
LICENSE_FILE_IPL=	${WRKSRC}/license.txt
LICENSE_PERMS_IPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=			${WRKDIR}/700Series/FreeBSDx64
NO_BUILD=		yes
NO_ARCH=		yes
NO_ARCH_IGNORE=		nvmupdate64e

SUB_FILES=	nvmupdate-40g
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

NVMUPDATE_DIR=	intel-nvmupdate-40g

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR} "! -name 'nvmupdate64e'"
	${INSTALL_PROGRAM} ${WRKSRC}/nvmupdate64e ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate-40g ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
