# ex:ts=8
# New ports collection makefile for:	fxt
# Date created:			Nov 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	fxt
PORTVERSION=	2004.10.25
CATEGORIES=	math
MASTER_SITES=	http://www.jjj.de/fxt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FFT code and related stuff

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GCC=	3.4
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ENV=	CXX="${CXX}" OFLAGS="${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|^OFLAGS|#OFLAGS|g ; \
		 s|^ARCHFLAG|#ARCHFLAG|g ; \
		 s|^WFLAGS|#WFLAGS|g ; \
		 s|^GFLAGS|#GFLAGS|g ; \
		 s|^PFLAGS|#PFLAGS|g ; \
		 s|^FXT_CXXFLAGS|#FXT_CXXFLAGS|g' ${WRKSRC}/makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libfxt.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/fxt
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/fxt
.for dir in aux0 aux1 aux2 bits bmat bpol chirpzt correlation comb \
	comb/bucket convolution dctdst demo ds fft fht graph graph/bucket \
	haar matrix matrixfft mod mult ntt perm perm/bucket realfft simplfft \
	sort sort/bucket test walsh wavelet
	@${MKDIR} ${PREFIX}/include/fxt/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.h ${PREFIX}/include/fxt/${dir}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/00*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
