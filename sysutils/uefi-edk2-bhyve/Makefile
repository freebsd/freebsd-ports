# $FreeBSD$

PORTNAME=	uefi-edk2-bhyve
DISTVERSION=	g20190424
PORTEPOCH=	2
CATEGORIES=	sysutils

MAINTAINER=	bcran@FreeBSD.org
COMMENT=	UEFI-EDK2 firmware for bhyve

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		gcc${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=3.4:databases/py-sqlite3@${PY_FLAVOR}

USES=		gmake \
		python:3.4+,build

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd openssl:ssl
GH_PROJECT=	uefi-edk2 openssl:ssl
GH_TAGNAME=	bhyve/edk2-stable201903 OpenSSL_1_1_0j:ssl
GH_SUBDIR=	CryptoPkg/Library/OpensslLib/openssl:ssl

MAKE_ARGS=	EXTRA_LDFLAGS=-static

PLIST_FILES=	share/uefi-firmware/BHYVE_UEFI_CODE${PLIST_SUFFIX}-devel.fd \
		share/uefi-firmware/BHYVE_UEFI_VARS${PLIST_SUFFIX}-devel.fd

OPTIONS_DEFINE= DEBUG HTTP_BOOT
OPTIONS_DEFAULT=HTTP_BOOT

DEBUG_DESC=	Build a debug configuration
HTTP_BOOT_DESC= Build with HTTP(S) boot support

DEBUG_VARS=	uefi_target=DEBUG
DEBUG_VARS_OFF= uefi_target=RELEASE
HTTP_BOOT_VARS= build_args+=-DHTTP_BOOT_ENABLE=TRUE

BUILD_ARGS=	-DDEBUG_ON_SERIAL_PORT=TRUE

post-patch:
	${MKDIR} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE};
	${LN} -sf ${LOCALBASE}/bin/gcc${GCC_DEFAULT} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc
	${LN} -sf ${LOCALBASE}/bin/gcc${GCC_DEFAULT} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/cc
	${LN} -sf ${LOCALBASE}/bin/g++${GCC_DEFAULT} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/g++
	${LN} -sf ${LOCALBASE}/bin/ld ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/ld
	${LN} -sf ${LOCALBASE}/bin/gmake ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/make
	${LN} -sf ${LOCALBASE}/bin/gcc-ar${GCC_DEFAULT} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc-ar
	${LN} -sf ${LOCALBASE}/bin/gcc-nm${GCC_DEFAULT} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc-nm
	${LN} -sf ${LOCALBASE}/bin/objcopy ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/objcopy
	${LN} -sf ${PYTHON_CMD} ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/python
	${LN} -sf ${LOCALBASE}/bin/nasm ${WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/nasm

do-build:
	bash -c "cd ${WRKSRC}; . ./edksetup.sh; ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} -C ${WRKSRC}/BaseTools"
	bash -c " \
		cd ${WRKSRC}; \
		unset ARCH; unset MAKEFLAGS; \
		. ./edksetup.sh; \
		build -t GCC5 -a X64 -b ${UEFI_TARGET} -p OvmfPkg/OvmfPkgX64.dsc ${BUILD_ARGS} \
	"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uefi-firmware/
	${INSTALL} ${WRKSRC}/Build/OvmfX64/${UEFI_TARGET}_GCC5/FV/OVMF_CODE.fd \
		${STAGEDIR}${PREFIX}/share/uefi-firmware/BHYVE_UEFI_CODE${PLIST_SUFFIX}-devel.fd
	${INSTALL} ${WRKSRC}/Build/OvmfX64/${UEFI_TARGET}_GCC5/FV/OVMF_VARS.fd \
		${STAGEDIR}${PREFIX}/share/uefi-firmware/BHYVE_UEFI_VARS${PLIST_SUFFIX}-devel.fd

.include <bsd.port.mk>
