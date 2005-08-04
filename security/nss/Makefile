# Ports collection Makefile for:	nss
# Date created:				18 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nss
PORTVERSION=	3.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	security/nss/releases/NSS_${PORTVERSION:S/./_/g}_RTM/src

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries to support development of security-enabled applications

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	nspr4.1:${PORTSDIR}/devel/nspr

WRKSRC=		${WRKDIR}/${DISTNAME}/mozilla/security/nss

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
MAKE_ENV=	BSD_LDOPTS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		BUILD_OPT=1
ALL_TARGET=	nss_build_all
CFLAGS+=	-I${LOCALBASE}/include/nspr

DIST=		${WRKSRC:H:H}/dist

CONFLICTS=	btoa-5.* digest-[0-9]* emboss-2.* oases-2.* p5-PAR-0.* \
		qmail-ldap2-[0-9]*

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	core dumps on alpha during build
.endif

EXTERNALS=	CVS dbm security/nss/cmd/zlib
EXTRACT_AFTER_ARGS=| ${TAR} -xf -	\
	${EXTERNALS:C,^,--exclude ${DISTNAME}/mozilla/,}

post-patch:
	@${REINPLACE_CMD} -e "s|-pthread|${PTHREAD_LIBS}|g" \
		${WRKSRC:H:H}/security/coreconf/FreeBSD.mk

BINS=${DIST}/${OPSYS}${OSREL}_OPT.OBJ

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

#.if defined(PARALLEL_PACKAGE_BUILD) && ${OSVERSION} >= 500000
#post-build: test
#.else
post-build:
	#
	# Please, consider running ``make test'' now and fixing any problems
	# and/or reporting them to ${MAINTAINER} . Thanks!
	#
#.endif

do-install:
	${MKDIR} ${PREFIX}/include/nss
	${TAR} -C ${DIST}/public --dereference -cf - . | \
		${TAR} -C ${PREFIX}/include/nss -xf -
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib/*.so.1 \
		${PREFIX}/lib
	${INSTALL_PROGRAM} ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/bin/* \
		${PREFIX}/bin
	cd ${DIST}/FreeBSD${OSREL:C/.$/*/}_OPT.OBJ/lib && \
		${TAR} -cf - *.so | ${TAR} --unlink -C ${PREFIX}/lib -xf -

.include <bsd.port.post.mk>
