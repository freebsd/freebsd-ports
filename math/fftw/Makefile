# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		ftp://ftp.fftw.org/pub/fftw/old/ 	\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE
COMMENT=	Fast C routines to compute the Discrete Fourier Transform

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--enable-shared
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

post-extract:
	@${RM} ${WRKSRC}/doc/fftw.info*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/fftw.ps ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
