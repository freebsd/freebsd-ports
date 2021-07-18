PORTNAME=	uefi-edk2-bhyve
PORTVERSION=	g20210226
PORTEPOCH=	2
CATEGORIES=	sysutils

MAINTAINER=	bcran@FreeBSD.org
COMMENT=	UEFI EDK2 firmware for bhyve

LICENSE=	BSD2CLAUSE+PATENT
LICENSE_GROUPS=	FSF OSI COPYFREE
LICENSE_NAME=	BSD-2-Clause Plus Patent License
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	bhyve firmware has only been ported to X64

BUILD_DEPENDS=	nasm:devel/nasm \
		bash:shells/bash

USES=		gmake \
		python:3.7+,build
USE_GCC=	yes:build
USE_GITHUB=	yes
GH_ACCOUNT=	tianocore
GH_PROJECT=	edk2
GH_TAGNAME=	edk2-stable202102
GH_TUPLE=	ucb-bar:berkeley-softfloat-3:master:softfloat/ArmPkg/Library/ArmSoftFloatLib/berkeley-softfloat-3 \
		google:brotli:v1.0.7-17-g666c328:brotli/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli \
		openssl:openssl:OpenSSL_1_1_1g:openssl/CryptoPkg/Library/OpensslLib/openssl \
		kkos:oniguruma:v6.9.4_mark1:oniguruma/MdeModulePkg/Universal/RegularExpressionDxe/oniguruma \
		akheron:jansson:v2.13.1:jansson/RedfishPkg/Library/JsonLib/jansson \

BINARY_ALIAS=	make=${LOCALBASE}/bin/gmake \
		gcc=${LOCALBASE}/bin/gcc${GCC_DEFAULT} \
		gcc-ar=${LOCALBASE}/bin/gcc-ar${GCC_DEFAULT} \
		g++=${LOCALBASE}/bin/g++${GCC_DEFAULT} \
		python3=${PYTHON_CMD} python=${PYTHON_CMD}

PLAT_ARCH=	X64
PLAT_FILE=	OvmfPkg/Bhyve/BhyveX64.dsc
PLAT_RESULT=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE.fd
PLAT_RESULT_CODE=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE_CODE.fd
PLAT_RESULT_VARS=	BhyveX64/${PLAT_TARGET}_GCC5/FV/BHYVE_VARS.fd

PLIST_FILES=	${PREFIX}/share/uefi-firmware/BHYVE_UEFI.fd      \
		${PREFIX}/share/uefi-firmware/BHYVE_UEFI_CODE.fd \
		${PREFIX}/share/uefi-firmware/BHYVE_UEFI_VARS.fd

OPTIONS_DEFINE=	DEBUG HTTP_BOOT
OPTIONS_DEFAULT=	HTTP_BOOT

DEBUG_DESC=	Build a debug configuration
HTTP_BOOT_DESC=	Build with HTTP(S) boot support

DEBUG_VARS=	PLAT_TARGET=DEBUG
DEBUG_VARS_OFF=	PLAT_TARGET=RELEASE
HTTP_BOOT_VARS=	PLAT_ARGS+=-DNETWORK_HTTP_BOOT_ENABLE=TRUE

PLAT_ARGS+=	-DDEBUG_ON_SERIAL_PORT=TRUE

# Emulate source edk2/edksetup.sh
MAKE_ENV+=	WORKSPACE=${WRKDIR} \
		PACKAGES_PATH=${WRKDIR}/edk2-${GH_TAGNAME} \
		CONF_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/Conf \
		EDK_TOOLS_PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools \
		PATH=${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/BinWrappers/PosixLike:${PATH} \
		PYTHON_COMMAND=python3 \
		PYTHONHASHSEED=1

# We can't have two submodule with the same origin in GH_TUPLE
post-extract:
	(cd ${WRKDIR}/edk2-${GH_TAGNAME}/MdeModulePkg/Library/BrotliCustomDecompressLib/brotli && tar cf - * | tar xf - -C ../../../../BaseTools/Source/C/BrotliCompress/brotli)

do-build:
	# This is normaly done during source edksetup.sh
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/build_rule.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/build_rule.txt)
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/tools_def.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/tools_def.txt)
	(cp ${WRKDIR}/edk2-${GH_TAGNAME}/BaseTools/Conf/target.template ${WRKDIR}/edk2-${GH_TAGNAME}/Conf/target.txt)
	# Build the basetools
	(cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C edk2-${GH_TAGNAME}/BaseTools -j ${MAKE_JOBS_NUMBER} ${_MAKE_JOBS})
	# Build EDK2
	(cd ${WRKDIR}/edk2-${GH_TAGNAME} && ${SETENV} ${MAKE_ENV} BaseTools/BinWrappers/PosixLike/build -a ${PLAT_ARCH} -p ${PLAT_FILE} -n ${MAKE_JOBS_NUMBER} -t GCC5 -b ${PLAT_TARGET} ${PLAT_ARGS})

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/BHYVE_UEFI.fd
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_CODE} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/BHYVE_UEFI_CODE.fd
	${INSTALL_DATA} ${WRKDIR}/Build/${PLAT_RESULT_VARS} ${STAGEDIR}/${PREFIX}/share/uefi-firmware/BHYVE_UEFI_VARS.fd

.include <bsd.port.mk>
