PORTNAME=	uefi-edk2-qemu
DISTVERSION=	g20191122
CATEGORIES=	sysutils

MAINTAINER=	bcran@FreeBSD.org
COMMENT=	OVMF package providing UEFI system firmware for QEMU

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:databases/py-sqlite3@${PY_FLAVOR}

FLAVORS=	x86_64 i386

USES=		gmake \
		python:3.4+,build
USE_GCC=	yes:build

x86_64_PKGNAMESUFFIX=	-x86_64
i386_PKGNAMESUFFIX=	-i386

USE_GITHUB=	yes
GH_ACCOUNT=	tianocore openssl:ssl
GH_PROJECT=	edk2 openssl:ssl
GH_TAGNAME=	edk2-stable201911 c3656cc594daac8167721dde7220f0e59ae146fc:ssl
GH_SUBDIR=	CryptoPkg/Library/OpensslLib/openssl:ssl

PLIST_FILES=	share/uefi-edk2-qemu/QEMU_UEFI_CODE${PLIST_SUFFIX}-${PKGSUFFIX}.fd \
		share/uefi-edk2-qemu/QEMU_UEFI_VARS${PLIST_SUFFIX}-${PKGSUFFIX}.fd

MAKE_ARGS=	EXTRA_LDFLAGS=-static
BUILD_ARGS=	-DDEBUG_ON_SERIAL_PORT=TRUE

OPTIONS_DEFINE=	DEBUG HTTP_BOOT
OPTIONS_DEFAULT=HTTP_BOOT

DEBUG_DESC=	Build a debug configuration
HTTP_BOOT_DESC=	Build with HTTP(S) boot support

DEBUG_VARS=	uefi_target=DEBUG
DEBUG_VARS_OFF=	uefi_target=RELEASE
HTTP_BOOT_VARS=	build_args+=-DHTTP_BOOT_ENABLE=TRUE

.if "${FLAVOR:U}" != i386
EDK2ARCH=X64
EDK2BLDDIR=X64
PKGSUFFIX=x86_64
.endif

.if ${FLAVOR:U} == i386
EDK2ARCH=IA32
EDK2BLDDIR=Ia32
PKGSUFFIX=i386
.endif

post-patch:
	${MKDIR} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE};
	${LN} -sf ${LOCALBASE}/bin/gcc${GCC_DEFAULT} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc
	${LN} -sf ${LOCALBASE}/bin/gcc${GCC_DEFAULT} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/cc
	${LN} -sf ${LOCALBASE}/bin/g++${GCC_DEFAULT} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/g++
	${LN} -sf ${LOCALBASE}/bin/ld ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/ld
	${LN} -sf ${LOCALBASE}/bin/gmake ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/make
	${LN} -sf ${LOCALBASE}/bin/gcc-ar${GCC_DEFAULT} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc-ar
	${LN} -sf ${LOCALBASE}/bin/gcc-nm${GCC_DEFAULT} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/gcc-nm
	${LN} -sf ${LOCALBASE}/bin/objcopy ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/objcopy
	${LN} -sf ${PYTHON_CMD} ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/python
	${LN} -sf ${LOCALBASE}/bin/nasm ${BUILD_WRKSRC}/BaseTools/Bin/FreeBSD-${MACHINE}/nasm

do-build:
	bash -c "cd ${WRKSRC}; . ./edksetup.sh; ${MAKE_CMD} -j4 ${MAKE_ARGS} -C ${WRKSRC}/BaseTools"
	bash -c " \
		cd ${BUILD_WRKSRC}; \
		unset ARCH; unset MAKEFLAGS; \
		. ./edksetup.sh; \
		build -t GCC5 -a ${EDK2ARCH} -b ${UEFI_TARGET} -p OvmfPkg/OvmfPkg${EDK2ARCH}.dsc ${BUILD_ARGS} \
	"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uefi-edk2-qemu/
	${INSTALL} ${BUILD_WRKSRC}/Build/Ovmf${EDK2BLDDIR}/${UEFI_TARGET}_GCC5/FV/OVMF_CODE.fd \
		${STAGEDIR}${PREFIX}/share/uefi-edk2-qemu/QEMU_UEFI_CODE${PLIST_SUFFIX}-${PKGSUFFIX}.fd
	${INSTALL} ${BUILD_WRKSRC}/Build/Ovmf${EDK2BLDDIR}/${UEFI_TARGET}_GCC5/FV/OVMF_VARS.fd \
		${STAGEDIR}${PREFIX}/share/uefi-edk2-qemu/QEMU_UEFI_VARS${PLIST_SUFFIX}-${PKGSUFFIX}.fd

.include <bsd.port.mk>
