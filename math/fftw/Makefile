# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw
PORTVERSION=	2.1.5
PORTREVISION?=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
PKGNAMESUFFIX=	${FFTW_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

# current flavors: default, float
FFTW_FLAVOR?=	default
FFTW_SUFIX=

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes
PLIST_SUB=	FFTW_SUFX="${FFTW_SUFX}"

.include <bsd.port.pre.mk>

.if ${FFTW_FLAVOR}=="float"
CONFIGURE_ARGS+=	--enable-float --enable-type-prefix

FFTW_SUFX=		s
FFTW_PKGNAMESUFFIX=	-float

INSTALL_TARGET=		install-exec
PLIST_SUB+=	DEF="@comment "
.else
INFO=			fftw
PLIST_SUB+=	DEF=""
.endif

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/fftw.info*

post-install:
.if ${FFTW_FLAVOR}=="default"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.ps ${DOCSDIR}/fftw.ps
.endif
.endif

.include <bsd.port.post.mk>
