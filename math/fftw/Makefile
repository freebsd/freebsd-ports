# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw
PORTVERSION=	2.1.5
PORTREVISION?=	6
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
PKGNAMESUFFIX=	${FFTW_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

BROKEN=		does not configure

LICENSE=	GPLv2

# current flavors: default, float
FFTW_FLAVOR?=	default
FFTW_SUFIX=

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:env libtool
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-shared
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	FFTW_SUFX="${FFTW_SUFX}"

.include <bsd.port.pre.mk>

.if ${FFTW_FLAVOR}=="float"
CONFIGURE_ARGS+=	--enable-float --enable-type-prefix
FFTW_SUFX=		s
FFTW_PKGNAMESUFFIX=	-float
PLIST_SUB+=	DEF="@comment "
.else
INFO=			fftw
PLIST_SUB+=	DEF=""
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

.if ${ARCH} == "sparc64"
BROKEN=		does not build
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/fftw.info*
.if ${FFTW_FLAVOR}=="float"
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in
.endif

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF})

post-install:
.if ${FFTW_FLAVOR}=="default"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.ps ${DOCSDIR}/fftw.ps
.endif
.endif

regression-test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
