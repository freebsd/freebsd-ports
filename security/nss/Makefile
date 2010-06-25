# Ports collection Makefile for:	nss
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom ports-experimental/security/nss/Makefile,v 1.4 2008/02/23 15:47:28 ahze Exp $

PORTNAME=	nss
PORTVERSION=	${_MAJOR}.${_MINOR}.${_PATCH}
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_RTM/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries to support development of security-enabled applications

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

_MAJOR=	3
_MINOR=	12
_PATCH=	6

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/security/nss

MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	${PREFIX}/lib/nss
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ENV=	BSD_LDOPTS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		BUILD_OPT=1 NSS_ENABLE_ECC=1 NSS_USE_SYSTEM_SQLITE=1
ALL_TARGET=	nss_build_all
CFLAGS+=	-I${LOCALBASE}/include/nspr -L${LOCALBASE}/lib

DIST=		${WRKSRC:H:H}/dist

EXTERNALS=	CVS dbm security/nss/cmd/zlib nsprpub security/dbm
EXTRACT_AFTER_ARGS=| ${TAR} -xf -	\
	${EXTERNALS:C,^,--exclude ${DISTNAME}/mozilla/,}

BINS=${DIST}/${OPSYS}${OSREL}_OPT.OBJ

INSTALL_BINS=	certcgi certutil checkcert cmsutil crlutil derdump makepqg \
		mangle modutil ocspclnt oidcalc p7content p7env p7sign \
		p7verify pk12util rsaperf shlibsign signtool signver \
		ssltap strsclnt symkeyutil vfychain vfyserv

test:
	cd ${WRKSRC}/tests;	\
		${SETENV} PATH="${BINS}/bin:${PATH}" \
		    LD_LIBRARY_PATH="${BINS}/lib" \
			./all.sh
	@if ${GREP} -F '>Failed<'	\
	    ${WRKSRC:H:H}/tests_results/security/*/results.html; then	\
		echo "Some tests have failed. Let ${MAINTAINER} know.";	\
		exit 1;	\
	else	\
		echo "All tests succeeded. Good news.";	\
	fi

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC:H:H}/security/coreconf/FreeBSD.mk
	@${SED} -e 's|@exec_prefix@|${PREFIX}|; \
		s|@includedir@|${PREFIX}/include/nss|; \
		s|@libdir@|${PREFIX}/lib/nss|; \
		s|@prefix@|${PREFIX}|' \
		${FILESDIR}/nss-config.in >${WRKDIR}/nss-config
	@${SED} -e 's|@PREFIX@|${PREFIX}|; s|@PORTVERSION@|${PORTVERSION}|' \
		${FILESDIR}/nss.pc.in >${WRKDIR}/nss.pc
.for i in MAJOR MINOR PATCH
	@${SED} -i.${i} -e 's|@${i}@|${_${i}}|' ${WRKDIR}/nss-config
.endfor
	@cd ${WRKSRC} && \
		${FIND} . -name "*.c" -o -name "*.h" | \
		${XARGS} ${REINPLACE_CMD} -e 's|"nspr.h"|<nspr.h>|'

do-install:
	${MKDIR} ${PREFIX}/include/nss/nss ${PREFIX}/lib/nss
	${FIND} ${DIST}/public/nss -type l \
	    	-exec ${INSTALL_DATA} {} ${PREFIX}/include/nss/nss \;
	${INSTALL_DATA} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib/*.so.1 \
		${PREFIX}/lib/nss
	${INSTALL_DATA} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib/libcrmf.a \
	    	${PREFIX}/lib/nss
.for bin in ${INSTALL_BINS}
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/bin/${bin} \
		${PREFIX}/bin
.endfor
	cd ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib && \
	    	${TAR} -cf - *.so | ${TAR} --unlink -C ${PREFIX}/lib/nss -xf -
	${INSTALL_SCRIPT} ${WRKDIR}/nss-config ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/nss.pc ${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
