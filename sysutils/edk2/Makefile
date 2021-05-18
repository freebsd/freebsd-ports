PORTNAME=	edk2
PORTVERSION=	g202005
CATEGORIES=	sysutils

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	EDK2 Firmware for ${FLAVOR}

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	This port only provides firmware for aarch64 and amd64 machine

PKGNAMESUFFIX=	-${FLAVOR:C/_/-/g}
FLAVORS=	macchiatobin rpi3 rpi4 xen_x64
FLAVOR?=	macchiatobin

USES=	gmake python:3.7+,build

BUILD_DEPENDS+=	gcc8:lang/gcc8 \
		dtc>=1.4.1:sysutils/dtc \
		bash:shells/bash

# Both platform and non-osi repository don't have release, use latest known to work tag
PLATFORM_TAG=	b716f363
NONOSI_TAG=	f8023973

USE_GITHUB=	yes
GH_ACCOUNT=	tianocore
GH_TAGNAME=	edk2-stable202005
GH_TUPLE=	tianocore:edk2-platforms:${PLATFORM_TAG}:platforms \
		tianocore:edk2-non-osi:${NONOSI_TAG}:nonosi \
		openssl:openssl:OpenSSL_1_1_1d-2-gc3656cc594:openssl/CryptoPkg/Library/OpensslLib/openssl \
		ucb-bar:berkeley-softfloat-3:master:softfloat/ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3 \
		kkos:oniguruma:v6.9.4_mark1:oniguruma/MdeModulePkg/Universal/RegularExpressionDxe/oniguruma \
		google:brotli:v1.0.7-17-g666c328:brotli/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli

BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake \
		dtc=${LOCALBASE}/bin/dtc \
		gcc=${LOCALBASE}/bin/gcc8 \
		gcc-ar=${LOCALBASE}/bin/gcc-ar8 \
		g++=${LOCALBASE}/bin/g++8 \
		python3=${PYTHON_CMD} python=${PYTHON_CMD}

.if ${FLAVOR} == macchiatobin
PLAT=		macchiatobin
PLAT_ARCH=	AARCH64
PLAT_ARGS=	-D X64EMU_ENABLE=TRUE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/SolidRun/Armada80x0McBin/Armada80x0McBin.dsc
PLAT_RESULT=	Armada80x0McBin-AARCH64/${PLAT_TARGET}_GCC5/FV/ARMADA_EFI.fd
PLAT_FILENAME=	ARMADA_EFI.fd
.endif

.if ${FLAVOR} == rpi3
PLAT=		rpi3
PLAT_ARCH=	AARCH64
PLAT_ARGS=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi3/RPi3.dsc
PLAT_RESULT=	RPi3/${PLAT_TARGET}_GCC5/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == rpi4
PLAT=		rpi4
PLAT_ARCH=	AARCH64
PLAT_ARGS=	-D X64EMU_ENABLE=FALSE -D CAPSULE_ENABLE=FALSE
PLAT_TARGET=	RELEASE
PLATFILE=	Platform/RaspberryPi/RPi4/RPi4.dsc
PLAT_RESULT=	RPi4/${PLAT_TARGET}_GCC5/FV/RPI_EFI.fd
PLAT_FILENAME=	RPI_EFI.fd
.endif

.if ${FLAVOR} == xen_x64
PLAT=		xen
PLAT_ARCH=	X64
PLAT_TARGET=	RELEASE
PLATFILE=	OvmfPkg/OvmfXen.dsc
PLAT_RESULT=	OvmfXen/${PLAT_TARGET}_GCC5/FV/OVMF.fd
PLAT_FILENAME=	XEN_X64_EFI.fd
.endif

PLIST_FILES=	${PREFIX}/share/${PORTNAME}-${PLAT}/${PLAT_FILENAME}

# Emulate source edk2/edksetup.sh
MAKE_ENV+=	WORKSPACE=${WRKDIR} \
		PACKAGES_PATH=${WRKDIR}/edk2-${GH_TAGNAME}:${WRKDIR}/edk2-platforms-${PLATFORM_TAG}:${WRKDIR}/edk2-non-osi-${NONOSI_TAG} \
		CONF_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/Conf \
		EDK_TOOLS_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools \
		PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/BinWrappers/PosixLike:${PATH} \
		PYTHON_COMMAND=python3 \
		PYTHONHASHSEED=1

.if ${PLAT_ARCH} == AARCH64
BUILD_DEPENDS+=	aarch64-none-elf-gcc:devel/aarch64-none-elf-gcc
MAKE_ENV+=	GCC5_AARCH64_PREFIX=aarch64-none-elf-
.endif

.if ${PLAT_ARCH} == X64
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

.include <bsd.port.mk>
