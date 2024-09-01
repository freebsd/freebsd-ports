PORTNAME=	edk2
PORTVERSION=	g202308
PORTREVISION=	5
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	EDK2 Firmware for ${FLAVOR}
WWW=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only provides firmware for aarch64 and amd64

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	macchiatobin fvp rpi3 rpi4 xen_x64 bhyve qemu_x64 qemu_i386

USES=	cpe gmake python:build
CPE_VENDOR=	tianocore
USE_GCC=	yes:build

BUILD_DEPENDS+=	dtc>=1.4.1:sysutils/dtc \
		bash:shells/bash

# Both platform and non-osi repository don't have release, use latest known to work tag
PLATFORM_TAG=	e509ac5a72
NONOSI_TAG=	8c09bd0955

USE_GITHUB=	yes
GH_ACCOUNT=	tianocore
GH_TAGNAME=	edk2-stable202308
GH_TUPLE=	tianocore:edk2-platforms:${PLATFORM_TAG}:platforms \
		tianocore:edk2-non-osi:${NONOSI_TAG}:nonosi \
		google:brotli:v1.0.9-35-gf4153a0:brotli/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli \
		google:googletest:release-1.8.0-2983-g86add134:googletest/UnitTestFrameworkPkg/Library/GoogleTestLib/googletest \
		MIPI-Alliance:public-mipi-sys-t:v1.1+edk2:mipisyst/MdePkg/Library/MipiSysTLib/mipisyst \
		openssl:openssl:openssl-3.0.9:openssl/CryptoPkg/Library/OpensslLib/openssl \
		tianocore:edk2-cmocka:cmocka-1.1.5-23-g1cc9cde:cmocka/UnitTestFrameworkPkg/Library/CmockaLib/cmocka

.include <bsd.port.pre.mk>

# Heavily dependent on bsd.port.pre.mk definitions for lang/gcc* details:
BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake \
		dtc=${LOCALBASE}/bin/dtc \
		ar=${AR} \
		gcc=${LOCALBASE}/bin/${CC} \
		gcc-ar=${LOCALBASE}/bin/${CC:S/gcc/&-ar/} \
		g++=${LOCALBASE}/bin/${CXX} \
		python3=${PYTHON_CMD} python=${PYTHON_CMD}

# Avoid: "ld-elf.so.1: /lib/libgcc_s.so.1: version GCC_4.5.0
#         required by /usr/local/lib/gcc11/libstdc++.so.6 not found"
# (that is from /lib/libgcc_s.so.1 having incomplete/inaccurate
# coverage for aarch64 g++ code generation's use of libgcc_s.so.1 ):
EXTRA_LDFLAGS+=	-Wl,-rpath=${_GCC_RUNTIME}

# Global args
PLAT_ARGS=	-D NETWORK_IP6_ENABLE

.if ${FLAVOR} == fvp
PLAT=		fvp
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/ARM/VExpressPkg/ArmVExpress-FVP-AArch64.dsc
PLAT_RESULT=	ArmVExpress-FVP-AArch64/${PLAT_TARGET}_GCC5/FV/FVP_AARCH64_EFI.fd
PLAT_FILENAME=	FVP_AARCH64_EFI.fd
.endif

.if ${FLAVOR} == macchiatobin
PLAT=		macchiatobin
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=TRUE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/SolidRun/Armada80x0McBin/Armada80x0McBin.dsc
PLAT_RESULT=	Armada80x0McBin-AARCH64/${PLAT_TARGET}_GCC5/FV/ARMADA_EFI.fd
PLAT_FILENAME=	ARMADA_EFI.fd
.endif

.if ${FLAVOR} == rpi3
PLAT=		rpi3
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi3/RPi3.dsc
PLAT_RESULT=	RPi3/${PLAT_TARGET}_GCC5/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == rpi4
PLAT=		rpi4
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi4/RPi4.dsc
PLAT_RESULT=	RPi4/${PLAT_TARGET}_GCC5/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == xen_x64
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not compile on hardware other than amd64
PLAT=		xen
PLAT_ARCH=	X64
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfXen.dsc
PLAT_RESULT=	OvmfXen/${PLAT_TARGET}_GCC5/FV/OVMF.fd
PLAT_FILENAME=	XEN_X64_EFI.fd
.endif

.if ${FLAVOR} == bhyve
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Bhyve only runs on x64
PLAT=		bhyve
PLAT_ARCH=	X64
PLAT_ARGS+=	-D SECURE_BOOT_ENABLE=TRUE -D TPM2_ENABLE=TRUE
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/Bhyve/BhyveX64.dsc
PLAT_RESULT=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE.fd
PLAT_RESULT_CODE=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE_CODE.fd
PLAT_RESULT_VARS=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE_VARS.fd
PLAT_FILENAME=	BHYVE_UEFI.fd
PLAT_FILENAME_CODE=	BHYVE_UEFI_CODE.fd
PLAT_FILENAME_VARS=	BHYVE_UEFI_VARS.fd
PATCHFILES=	ffce430d2b65d508a1604dc986ba16db3583943d.patch:-p1
.endif

.if ${FLAVOR} == qemu_x64
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not compile on hardware other than amd64
PLAT=		qemu
PLAT_ARCH=	X64
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfPkgX64.dsc
PLAT_RESULT=	OvmfX64/${PLAT_TARGET}_GCC5/FV/OVMF.fd
PLAT_RESULT_CODE=	OvmfX64/${PLAT_TARGET}_GCC5/FV/OVMF_CODE.fd
PLAT_RESULT_VARS=	OvmfX64/${PLAT_TARGET}_GCC5/FV/OVMF_VARS.fd
PLAT_FILENAME=	QEMU_UEFI-x86_64.fd
PLAT_FILENAME_CODE=	QEMU_UEFI_CODE-x86_64.fd
PLAT_FILENAME_VARS=	QEMU_UEFI_VARS-x86_64.fd
.endif

.if ${FLAVOR} == qemu_i386
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not compile on hardware other than amd64
PLAT=		qemu
PLAT_ARCH=	IA32
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfPkgIa32.dsc
PLAT_RESULT=	OvmfIa32/${PLAT_TARGET}_GCC5/FV/OVMF.fd
PLAT_RESULT_CODE=	OvmfIa32/${PLAT_TARGET}_GCC5/FV/OVMF_CODE.fd
PLAT_RESULT_VARS=	OvmfIa32/${PLAT_TARGET}_GCC5/FV/OVMF_VARS.fd
PLAT_FILENAME=	QEMU_UEFI-i386.fd
PLAT_FILENAME_CODE=	QEMU_UEFI_CODE-i386.fd
PLAT_FILENAME_VARS=	QEMU_UEFI_VARS-i386.fd
.endif

PLIST_FILES=	${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}
.if defined(PLAT_FILENAME_CODE)
PLIST_FILES+=	${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_CODE}
.endif
.if defined(PLAT_FILENAME_VARS)
PLIST_FILES+=	${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_VARS}
.endif
.if ${FLAVOR} == bhyve
PLIST_FILES+=	${PREFIX}/share/uefi-firmware/${PLAT_FILENAME}
PLIST_FILES+=	${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_CODE}
PLIST_FILES+=	${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_VARS}
.endif

# Emulate source edk2/edksetup.sh
MAKE_ENV+=	WORKSPACE=${WRKDIR} \
		PACKAGES_PATH=${WRKDIR}/edk2-${GH_TAGNAME}:${WRKDIR}/edk2-platforms-${PLATFORM_TAG}:${WRKDIR}/edk2-non-osi-${NONOSI_TAG} \
		CONF_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/Conf \
		EDK_TOOLS_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools \
		PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/BinWrappers/PosixLike:${PATH} \
		PYTHON_COMMAND=python3 \
		PYTHONHASHSEED=1 \
		EXTRA_LDFLAGS=${EXTRA_LDFLAGS}

.if ${PLAT_ARCH} == AARCH64 && ${ARCH} != aarch64
BUILD_DEPENDS+=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc
MAKE_ENV+=	GCC5_AARCH64_PREFIX=aarch64-none-elf-
.endif

.if ${PLAT_ARCH} == X64 || ${PLAT_ARCH} == IA32
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

# We can't have two submodule with the same origin in GH_TUPLE
post-extract:
	(cd ${WRKDIR}/edk2-${GH_TAGNAME}/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli && tar cf - * | tar xf - -C ../../../../BaseTools/Source/C/BrotliCompress/brotli)

do-build:
	# This is normaly done during source edksetup.sh
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/build_rule.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/build_rule.txt)
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/tools_def.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/tools_def.txt)
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/target.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/target.txt)
	# Build the basetools
	(cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C edk2-${GH_TAGNAME}/BaseTools ${_MAKE_JOBS})
	# Build EDK2
	(cd ${WRKDIR}/edk2-${GH_TAGNAME} && ${SETENV} ${MAKE_ENV} BaseTools/BinWrappers/PosixLike/build -a ${PLAT_ARCH} -p ${PLATFILE} -n ${MAKE_JOBS_NUMBER} -t GCC5 -b ${PLAT_TARGET} ${PLAT_ARGS})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}
.if defined(PLAT_FILENAME_CODE)
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_CODE}
.endif
.if defined(PLAT_FILENAME_VARS)
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_VARS} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_VARS}
.endif
.if ${FLAVOR} == bhyve
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}
	# For backwards compatibility
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME}
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_CODE} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_CODE}
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_VARS} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_VARS}
.endif

.include <bsd.port.post.mk>
