# New ports collection makefile for:	octave
# Date created:		8 September 1998
# Whom:			chuckr@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	octave
PORTVERSION=	2.1.71
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.octave.org/pub/octave/bleeding-edge/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/GNU/misc/octave/bleeding-edge/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-level interactive language for numerical computations

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		atlas.1:${PORTSDIR}/math/atlas

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INFO=		octave liboctave
MAN1=		octave.1 octave-bug.1 mkoctfile.1 octave-config.1

OCTAVE_VERSION=	${PORTVERSION}
GNU_HOST=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	OCTAVE_VERSION=${OCTAVE_VERSION} GNU_HOST=${GNU_HOST}

F77?=		f77

CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		F77="${F77}" \
		FFLAGS="${FFLAGS}"
CONFIGURE_ARGS=	--host=${GNU_HOST} \
		--with-blas="-L${LOCALBASE}/lib -lf77blas -lcblas -latlas" \
		--with-lapack=-lalapack \
		--enable-shared

SUB_FILES=	octave
SUB_LIST=	OCTAVE_VERSION="${OCTAVE_VERSION}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--disable-readline
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/octave ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/liboctave/liboctave.info ${PREFIX}/info
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq/Octave-FAQ.ps interpreter/octave.ps liboctave/liboctave.ps \
	refcard/refcard-a4.ps refcard/refcard-legal.ps refcard/refcard-letter.ps
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
