PORTNAME=	uefi-edk2-bhyve-csm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	bcran@FreeBSD.org
COMMENT=	UEFI EDK2 firmware for bhyve with CSM (16-bit BIOS)
WWW=		https://github.com/freebsd/uefi-edk2/tree/bhyve/UDK2014.SP1

LICENSE=	BSD2CLAUSE

DEPRECATED=     Requires old edk2 version and gcc 4.8.
EXPIRATION_DATE=2024-04-01

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	bash:shells/bash \
		nasm:devel/nasm \
		${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

USES=		gmake \
		python:2.7,build
USE_GCC=	4.8:build
USE_GITHUB=	yes
GH_ACCOUNT=	freebsd
GH_PROJECT=	uefi-edk2
GH_TAGNAME=	aa8d718

PLIST_FILES=	${PREFIX}/share/uefi-firmware/BHYVE_UEFI_CSM.fd

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	uefi_target=DEBUG
DEBUG_VARS_OFF=	uefi_target=RELEASE

MAKE_ARGS+=	AS=${LOCALBASE}/bin/as \
		AR=${LOCALBASE}/bin/ar \
		LD=${LOCALBASE}/bin/ld \
		OBJCOPY=${LOCALBASE}/bin/objcopy \
		CC=${LOCALBASE}/bin/gcc48 \
		CXX=${LOCALBASE}/bin/g++48

BUILD_ARGS=-DDEBUG_ON_SERIAL_PORT=TRUE -D FD_SIZE_2MB -DCSM_ENABLE=TRUE

post-extract:
	@${REINPLACE_CMD} -e 's|python|${PYTHON_CMD}|' ${WRKSRC}/BaseTools/Tests/GNUmakefile \
							${WRKSRC}/BaseTools/BinWrappers/PosixLike/*

do-build:
	unset ARCH; unset MAKEFLAGS; ${MAKE_CMD} ${MAKE_ARGS} -C ${BUILD_WRKSRC}/BaseTools
	${MKDIR} ${BUILD_WRKSRC}/Build;
	${LN} -sf ${LOCALBASE}/bin/gcc48 ${BUILD_WRKSRC}/Build/gcc
	${LN} -sf ${LOCALBASE}/bin/ld ${BUILD_WRKSRC}/Build/ld
	${LN} -sf ${LOCALBASE}/bin/gmake ${BUILD_WRKSRC}/Build/make
	${LN} -sf ${LOCALBASE}/bin/ar ${BUILD_WRKSRC}/Build/ar
	${LN} -sf ${LOCALBASE}/bin/objcopy ${BUILD_WRKSRC}/Build/objcopy
	${LN} -sf ${LOCALBASE}/bin/nasm ${BUILD_WRKSRC}/Build/nasm
	bash -c " \
		cd ${BUILD_WRKSRC}; \
		source edksetup.sh;\
		unset ARCH; unset MAKEFLAGS; \
		${MAKE_CMD} ${MAKE_ARGS} GCC48_BIN=${BUILD_WRKSRC}/Build/ -C ${BUILD_WRKSRC}/BhyvePkg/Csm/BhyveCsm16/"
	bash -c " \
		cd ${BUILD_WRKSRC}; \
		source edksetup.sh;\
		unset ARCH; unset MAKEFLAGS; \
		export GCC48_BIN=${BUILD_WRKSRC}/Build/; \
		build -t GCC48 -a X64 -b ${UEFI_TARGET} -p BhyvePkg/BhyvePkgX64.dsc ${BUILD_ARGS} \
	"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/uefi-firmware/
	${INSTALL} ${BUILD_WRKSRC}/Build/BhyveX64/${UEFI_TARGET}_GCC48/FV/BHYVE.fd \
		${STAGEDIR}${PREFIX}/share/uefi-firmware/BHYVE_UEFI_CSM.fd

.include <bsd.port.mk>
