# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nss
PORTVERSION=	3.27.2
#DISTVERSIONSUFFIX=	-with-ckbi-1.98
CATEGORIES=	security
MASTER_SITES=	MOZILLA/security/${PORTNAME}/releases/${DISTNAME:tu:C/[-.]/_/g}_RTM/src

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Libraries to support development of security-enabled applications

LICENSE=	MPL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zip:archivers/zip \
		nspr>=4.12:devel/nspr \
		sqlite3>=3.7.15:databases/sqlite3
LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libsqlite3.so:databases/sqlite3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/nss

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${PREFIX}/lib/nss
USES=		cpe gmake perl5
CPE_VENDOR=	mozilla
CPE_PRODUCT=	network_security_services
USE_PERL5=	build
MAKE_ENV=	LIBRARY_PATH="${LOCALBASE}/lib" \
		SQLITE_INCLUDE_DIR="${LOCALBASE}/include" \
		FREEBL_LOWHASH=1 \
		NSS_DISABLE_GTESTS=1 \
		NSS_USE_SYSTEM_SQLITE=1
CFLAGS+=	-I${LOCALBASE}/include/nspr

SUB_FILES=	nss-config nss.pc
SUB_LIST=	PORTVERSION=${PORTVERSION}

DIST=		${WRKSRC:H}/dist

EXTRACT_AFTER_ARGS=--exclude */lib/zlib --exclude */lib/dbm --exclude */lib/sqlite

INSTALL_BINS=	certcgi certutil cmsutil crlutil derdump makepqg \
		mangle modutil ocspclnt oidcalc p7content p7env p7sign \
		p7verify pk12util rsaperf shlibsign signtool signver \
		ssltap strsclnt symkeyutil vfychain vfyserv

OPTIONS_DEFINE=	DEBUG

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDEBUG}
MAKE_ENV+=	BUILD_OPT=1
BINS=		${DIST}/${OPSYS}${OSREL}_OPT.OBJ
.else
BINS=		${DIST}/${OPSYS}${OSREL}_DBG.OBJ
.endif

.if ${OPSYS} == FreeBSD && ${ARCH} == amd64
USE_BINUTILS=	# intel-gcm.s
CC+=	-B${LOCALBASE}/bin
.endif

check regression-test test:
	cd ${WRKSRC}/tests;	\
		${SETENV} PATH="${BINS}/bin:${PATH}" \
		    LD_LIBRARY_PATH="${BINS}/lib" \
		    ${MAKE_ENV}	\
			./all.sh
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
	${FIND} ${WRKSRC}/tests -name '*.sh' | ${XARGS} ${GREP} -l -F '/bin/bash' | \
		${XARGS} ${REINPLACE_CMD} -e 's|#! */bin/bash|#!${SH}|'

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nss/nss ${STAGEDIR}${PREFIX}/lib/nss
	${FIND} ${DIST}/public/nss -type l \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/include/nss/nss \;
	${INSTALL_LIB} ${BINS}/lib/*.so \
		${STAGEDIR}${PREFIX}/lib/nss
	${INSTALL_DATA} ${BINS}/lib/libcrmf.a \
		${STAGEDIR}${PREFIX}/lib/nss
.for bin in ${INSTALL_BINS}
	${INSTALL_PROGRAM} ${BINS}/bin/${bin} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/nss-config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/nss.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
