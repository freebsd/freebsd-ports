# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.62
CATEGORIES=	security
MASTER_SITES=	MOZILLA/security/${PORTNAME}/releases/${DISTNAME:tu:C/[-.]/_/g}_RTM/src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Libraries to support development of security-enabled applications

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libsqlite3.so:databases/sqlite3
TEST_DEPENDS=	bash:shells/bash

USES=		cpe gmake perl5

WRKSRC_SUBDIR=	nss

USE_LDCONFIG=	yes
CPE_VENDOR=	mozilla
CPE_PRODUCT=	network_security_services
USE_PERL5=	build
MAKE_ENV=	NSPR_LIB_DIR="${LOCALBASE}/lib" \
		SQLITE_INCLUDE_DIR="${LOCALBASE}/include" \
		FREEBL_LOWHASH=1 \
		NSS_ENABLE_WERROR=0 \
		NSS_DISABLE_GTESTS=1 \
		NSS_USE_SYSTEM_SQLITE=1
CFLAGS+=	-I${LOCALBASE}/include/nspr -Wno-error=unused-function

SUB_FILES=	nss-config nss.pc
SUB_LIST=	PORTVERSION=${PORTVERSION}

DIST=		${WRKSRC:H}/dist

EXTRACT_AFTER_ARGS=--exclude */lib/zlib --exclude */lib/dbm --exclude */lib/sqlite

INSTALL_BINS=	certutil cmsutil crlutil derdump makepqg \
		mangle modutil ocspclnt oidcalc p7content p7env p7sign \
		p7verify pk12util rsaperf shlibsign signtool signver \
		ssltap strsclnt symkeyutil vfychain vfyserv

OPTIONS_DEFINE=	DEBUG
OPTIONS_DEFINE_powerpc=		VSX
OPTIONS_DEFINE_powerpc64=	VSX

VSX_CFLAGS=	-DUSE_PPC_CRYPTO
VSX_DESC=	Use VSX optimized routines (POWER8 or newer)

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	BUILD_OPT=1
BINS=		${DIST}/${OPSYS}${OSREL}_OPT.OBJ
.else
BINS=		${DIST}/${OPSYS}${OSREL}_DBG.OBJ
.endif

.if ${ARCH} == armv6
MAKE_ENV+=	NSS_DISABLE_ARM32_NEON=1
.endif

.if ${ARCH} == powerpc64 || ${ARCH} == powerpc
EXTRA_PATCHES=	${FILESDIR}/${ARCH}${PPC_ABI:tl}-lib_freebl_scripts_gen.sh
USES+=		compiler:c++11-lang # -mcrypto -mvsx
.if ! ${PORT_OPTIONS:MVSX}
MAKE_ENV+=	NSS_DISABLE_ALTIVEC=1
.endif
.endif

.if ${OPSYS} == FreeBSD && ${ARCH} == amd64
USE_BINUTILS=	# intel-gcm.s
CC+=	-B${LOCALBASE}/bin
.endif

do-test:
	cd ${WRKSRC}/tests;	\
		${SETENV} PATH="${BINS}/bin:${PATH}" \
		    LD_LIBRARY_PATH="${BINS}/lib" \
		    ${MAKE_ENV}	\
			bash ./all.sh
	@if ${GREP} -Fh '>Failed<'	\
	    ${WRKSRC:H}/tests_results/security/*/results.html; then	\
		echo "Some tests have failed. Let ${MAINTAINER} know.";	\
		exit 1;	\
	else	\
		echo "All tests succeeded. Good news.";	\
	fi

post-patch:
	@${REINPLACE_CMD} '/NSS_DEFAULT_SYSTEM/s,/etc,${PREFIX}&,' \
		${WRKSRC}/lib/sysinit/nsssysinit.c
	@cd ${WRKSRC} && \
		${FIND} . -name "*.c" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|"nspr.h"|<nspr.h>|'

.if ${ARCH:Mpowerpc*}
pre-build:
	@cd ${WRKSRC}/lib/freebl/scripts && ./gen.sh
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nss ${STAGEDIR}${PREFIX}/lib
	${FIND} ${DIST}/public/nss -type l \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/include/nss \;
	${INSTALL_LIB} ${BINS}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${BINS}/lib/libcrmf.a \
		${STAGEDIR}${PREFIX}/lib/
.for bin in ${INSTALL_BINS}
	${INSTALL_PROGRAM} ${BINS}/bin/${bin} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/nss-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/nss.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
