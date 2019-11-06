# Created by: Sergey Kozlov <sergey.kozlov@intel.com>
# $FreeBSD$

PORTNAME=	nvmupdate
DISTVERSION=	7_00
CATEGORIES=	sysutils
MASTER_SITES=	https://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/ \
		http://downloadmirror.intel.com/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	25792/eng
PKGNAMEPREFIX=	intel-
DISTNAME=	700Series_NVMUpdatePackage_v${DISTVERSION}_FreeBSD

MAINTAINER=	freebsd@intel.com
COMMENT=	NVM Update Utility for Intel(R) Ethernet Adapters

BROKEN=		unfetchable

LICENSE=		IFL IPL
LICENSE_COMB=		multi

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
ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	not supported on anything other than amd64
IGNORE_DragonFly=	FreeBSD binary port

SUB_FILES=	nvmupdate
SUB_LIST=	NVMUPDATE_DIR=${NVMUPDATE_DIR}

NVMUPDATE_DIR=	intel-nvmupdate

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR} "! -name 'nvmupdate64e'"
	${INSTALL_PROGRAM} ${WRKSRC}/nvmupdate64e ${STAGEDIR}${PREFIX}/${NVMUPDATE_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/nvmupdate ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.post.mk>
