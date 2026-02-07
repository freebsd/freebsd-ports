PORTNAME=	edk2
PORTVERSION=	g202508
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	EDK2 Firmware for ${FLAVOR}
WWW=		https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	only provides firmware for aarch64 and amd64

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	bhyve macchiatobin fvp rpi3 rpi4 xen_x64 qemu_x64 qemu_i386

USES=	dos2unix cpe gmake python:build
CPE_VENDOR=	tianocore
USE_GCC=	yes
DOS2UNIX_FILES=	UefiCpuPkg/CpuDxe/CpuDxe.inf \
		UefiCpuPkg/CpuDxe/CpuDxe.c \
		UefiCpuPkg/CpuDxe/CpuPageTable.c \
		UefiCpuPkg/CpuDxe/CpuPageTable.h

BUILD_DEPENDS+=	dtc>=1.4.1:sysutils/dtc \
		bash:shells/bash

# Both platform and non-osi repository don't have release, use latest known to work tag
PLATFORM_TAG=	aa035ed7f469295802d51c7c001477e32da8a65f
NONOSI_TAG=	3415f616e08a0d9c7bd264cab674929a7b0f5e33

USE_GITHUB=	yes
GH_ACCOUNT=	tianocore
GH_TAGNAME=	edk2-stable202508
GH_TUPLE=	tianocore:edk2-platforms:${PLATFORM_TAG}:platforms \
		tianocore:edk2-non-osi:${NONOSI_TAG}:nonosi \
		tianocore:edk2-subhook:83d4e1ebef3588fae48b69a7352cc21801cb70bc:edk2_subhook/UnitTestFrameworkPkg/Library/SubhookLib/subhook \
		tianocore:edk2-cmocka:1cc9cde3448cdd2e000886a26acf1caac2db7cf1:edk2_cmocka/UnitTestFrameworkPkg/Library/CmockaLib/cmocka \
		openssl:openssl:aea7aaf2abb04789f5868cbabec406ea43aa84bf:openssl/CryptoPkg/Library/OpensslLib/openssl \
		kkos:oniguruma:4ef89209a239c1aea328cf13c05a2807e5c146d1:oniguruma/MdeModulePkg/Universal/RegularExpressionDxe/oniguruma \
		google:googletest:86add13493e5c881d7e4ba77fb91c1f57752b3a4:googletest/UnitTestFrameworkPkg/Library/GoogleTestLib/googletest \
		google:brotli:f4153a09f87cbb9c826d8fc12c74642bb2d879ea:brotli/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli \
		devicetree-org:pylibfdt:cfff805481bdea27f900c32698171286542b8d3c:pylibfdt/MdePkg/Library/BaseFdtLib/libfdt \
		akheron:jansson:e9ebfa7e77a6bee77df44e096b100e7131044059:jansson/RedfishPkg/Library/JsonLib/jansson \
		MIPI-Alliance:public-mipi-sys-t:370b5944c046bab043dd8b133727b2135af7747a:public_mipi_sys_t/MdePkg/Library/MipiSysTLib/mipisyst \
		DMTF:libspdm:98ef964e1e9a0c39c7efb67143d3a13a819432e0:libspdm/SecurityPkg/DeviceSecurity/SpdmLib/libspdm \
		ARMmbed:mbedtls:8c89224991adff88d53cd380f42a2baa36f91454:mbedtls/CryptoPkg/Library/MbedTlsLib/mbedtls

.include <bsd.port.pre.mk>

# Heavily dependent on bsd.port.pre.mk definitions for lang/gcc* details:
BINARY_ALIAS=	make=${GMAKE} \
		gcc=${LOCALBASE}/bin/${CC} \
		g++=${LOCALBASE}/bin/${CXX} \
		gcc-nm=${LOCALBASE}/bin/${CC:S/gcc/&-nm/} \
		gcc-ar=${LOCALBASE}/bin/${CC:S/gcc/&-ar/} \
		gcc-ranlib=${LOCALBASE}/bin/${CC:S/gcc/&-ranlib/} \
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
PLAT_RESULT=	ArmVExpress-FVP-AArch64/${PLAT_TARGET}_GCC/FV/FVP_AARCH64_EFI.fd
PLAT_FILENAME=	FVP_AARCH64_EFI.fd
.endif

.if ${FLAVOR} == macchiatobin
PLAT=		macchiatobin
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=TRUE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/SolidRun/Armada80x0McBin/Armada80x0McBin.dsc
PLAT_RESULT=	Armada80x0McBin-AARCH64/${PLAT_TARGET}_GCC/FV/ARMADA_EFI.fd
PLAT_FILENAME=	ARMADA_EFI.fd
.endif

.if ${FLAVOR} == rpi3
PLAT=		rpi3
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi3/RPi3.dsc
PLAT_RESULT=	RPi3/${PLAT_TARGET}_GCC/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == rpi4
PLAT=		rpi4
PLAT_ARCH=	AARCH64
PLAT_ARGS+=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi4/RPi4.dsc
PLAT_RESULT=	RPi4/${PLAT_TARGET}_GCC/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == xen_x64
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not compile on hardware other than amd64
PLAT=		xen
PLAT_ARCH=	X64
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfXen.dsc
PLAT_RESULT=	OvmfXen/${PLAT_TARGET}_GCC/FV/OVMF.fd
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
PLAT_RESULT=	BhyveX64/${PLAT_TARGET}_GCC/FV/BHYVE.fd
PLAT_RESULT_CODE=	BhyveX64/${PLAT_TARGET}_GCC/FV/BHYVE_CODE.fd
PLAT_RESULT_VARS=	BhyveX64/${PLAT_TARGET}_GCC/FV/BHYVE_VARS.fd
PLAT_FILENAME=	BHYVE_UEFI.fd
PLAT_FILENAME_CODE=	BHYVE_UEFI_CODE.fd
PLAT_FILENAME_VARS=	BHYVE_UEFI_VARS.fd
.endif

.if ${FLAVOR} == qemu_x64
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Do not compile on hardware other than amd64
PLAT=		qemu
PLAT_ARCH=	X64
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfPkgX64.dsc
PLAT_RESULT=	OvmfX64/${PLAT_TARGET}_GCC/FV/OVMF.fd
PLAT_RESULT_CODE=	OvmfX64/${PLAT_TARGET}_GCC/FV/OVMF_CODE.fd
PLAT_RESULT_VARS=	OvmfX64/${PLAT_TARGET}_GCC/FV/OVMF_VARS.fd
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
PLAT_RESULT=	OvmfIa32/${PLAT_TARGET}_GCC/FV/OVMF.fd
PLAT_RESULT_CODE=	OvmfIa32/${PLAT_TARGET}_GCC/FV/OVMF_CODE.fd
PLAT_RESULT_VARS=	OvmfIa32/${PLAT_TARGET}_GCC/FV/OVMF_VARS.fd
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

.if ${PLAT_ARCH} == AARCH64 && ${ARCH} != aarch64
BUILD_DEPENDS+=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc
MAKE_ENV+=	GCC_AARCH64_PREFIX=aarch64-none-elf-
.endif

.if ${PLAT_ARCH} == X64 || ${PLAT_ARCH} == IA32
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

MAKE_ENV+=	PYTHON_COMMAND=python3 \
		EXTRA_LDFLAGS=${EXTRA_LDFLAGS} \
		PACKAGES_PATH=${WRKDIR}/edk2-${GH_TAGNAME}:${WRKDIR}/edk2-platforms-${PLATFORM_TAG}:${WRKDIR}/edk2-non-osi-${NONOSI_TAG}

# custom logo for bhyve's ovmf
.if ${FLAVOR} == bhyve
MASTER_SITES+= LOCAL/dch/bhyve/
DISTFILES+=	BhyveLogo.bmp
EXTRACT_ONLY= ${DISTFILES:M*.gz*:C/.gz:.*/.gz/}
.endif

post-extract:
	# We can't have two submodule with the same origin in GH_TUPLE
	(cd ${WRKDIR}/edk2-${GH_TAGNAME} && ${CP} -a MdeModulePkg/Library/BrotliCustomDecompressLib/brotli/* BaseTools/Source/C/BrotliCompress/brotli)

.if ${FLAVOR} == bhyve
	(${CP} ${DISTDIR}/BhyveLogo.bmp ${WRKDIR}/edk2-${GH_TAGNAME}/MdeModulePkg/Logo/Logo.bmp)
.endif


do-build:
	# Just run a bash subshell for build instead of emulating edksetup.sh
	(bash -c ' \
		export ${MAKE_ENV} && \
		cd ${WRKDIR}/edk2-${GH_TAGNAME} && \
		${MAKE_CMD} -C BaseTools -j ${MAKE_JOBS_NUMBER} && \
		source edksetup.sh && \
		build -a ${PLAT_ARCH} -p ${PLATFILE} -n ${MAKE_JOBS_NUMBER} -t GCC -b ${PLAT_TARGET} ${PLAT_ARGS} \
	')

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/
	${INSTALL_DATA} ${WRKDIR}/edk2-${GH_TAGNAME}/Build/${PLAT_RESULT} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}
.if defined(PLAT_FILENAME_CODE)
	${INSTALL_DATA} ${WRKDIR}/edk2-${GH_TAGNAME}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_CODE}
.endif
.if defined(PLAT_FILENAME_VARS)
	${INSTALL_DATA} ${WRKDIR}/edk2-${GH_TAGNAME}/Build/${PLAT_RESULT_VARS} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_VARS}
.endif

.if ${FLAVOR} == bhyve
	# For now BHYVE cannot load the regular firmware file that contains vars so we just replace it with CODE
	${INSTALL_DATA} ${WRKDIR}/edk2-${GH_TAGNAME}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}
	# For backwards compatibility
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME}
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_CODE} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_CODE}
	${RLN} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME_VARS} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/${PLAT_FILENAME_VARS}
.endif

.include <bsd.port.post.mk>
