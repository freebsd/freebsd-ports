# Created by: Anton Shterenlikht
# $FreeBSD$

PORTNAME=	slatec
PORTVERSION=	4.1
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	NL/slatec/:slatec NL/blas/:blas
# Get d1mach.f, i1mach.f, r1mach.f from BLAS, rather than from Slatec:
# See Netlib FAQ #2.17: http://netlib.org/misc/faq.html#2.17
DISTFILES=	guide:slatec slatec_chk.tgz:slatec slatec_src.tgz:slatec \
		toc:slatec d1mach.f:blas i1mach.f:blas r1mach.f:blas
DIST_SUBDIR=	slatec
EXTRACT_ONLY=	slatec_src.tgz slatec_chk.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLATEC Common Mathematical Library

USES=		fortran uidfix
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/src
SHLIB_MAJOR=	1

PLIST_FILES=	lib/libslatec.a lib/libslatec.so lib/libslatec.so.${SHLIB_MAJOR}
PORTDOCS=	guide toc

LDFLAGS+=	${FFLAGS}
LDADD ?=	-lgfortran -lm
SRCCONF=	/dev/null
MAKE_ENV+=	LDADD="${LDADD}" SHLIB_MAJOR="${SHLIB_MAJOR}" \
		SRCCONF="${SRCCONF}"

OPTIONS_DEFINE=	DOCS PROFILE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE=	you have selected PROFILE option, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/libslatec_p.a
.else
MAKE_ENV+=	NO_PROFILE=
.endif

post-extract:
	@${CP} ${_DISTDIR}/[dir]1mach.f ${WRKSRC}
	@cd ${WRKDIR}; ${MV} dfmat.f dgvec.f duivp.f duvec.f fmat.f gvec.f \
	uivp.f uvec.f ${WRKSRC}
	@${CP} ${FILESDIR}/makefile.lib ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/makefile.test ${WRKDIR}/Makefile

TEST_VERBOSITY?=	1

check regression-test test: test-dynamic test-static

.for l in dynamic static
test-${l}: build
	@${ECHO_CMD} "****** Testing SLATEC ${l} library,"
	@${ECHO_CMD} "****** using a verbosity of ${TEST_VERBOSITY}."
	@${ECHO_CMD} "****** (The verbosity level can be selected by defining"
	@${ECHO_CMD} "****** TEST_VERBOSITY=0|1|2|3.)"
	@cd ${WRKDIR}; ${SETENV} ${MAKE_ENV} TEST_VERBOSITY="${TEST_VERBOSITY}" \
	${MAKE} ${_MAKE_JOBS} ${MAKE_ARGS} test-${l}

.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${_DISTDIR}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
