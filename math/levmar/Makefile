# New ports collection makefile for:    levmar
# Date created: 18 May 2010
# Whom:         Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	levmar
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ics.forth.gr/~lourakis/levmar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	A GPL-licensed library implementing the Levenberg-Marquardt algorithm

LICENSE=	GPLv2

USE_LDCONFIG=	yes
USE_FORTRAN=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgoto2.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas_r.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "reference"
LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == "gotoblas"
LIB_DEPENDS=	goto2:${PORTSDIR}/math/gotoblas \
		lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lpthread -lgoto2p
LAPACK=		-lpthread -lgoto2p
.elif ${WITH_BLAS} == "atlas"
LIB_DEPENDS=	atlas:${PORTSDIR}/math/atlas
BLAS=		-pthread -lptf77blas -lptcblas -latlas_r
LAPACK=		-pthread -lalapack_r
.endif

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LDADD="${LAPACK} ${BLAS}" LDFLAGS="${LDFLAGS}"
.for _u in AR NM RANLIB
MAKE_ENV+=	${_u}="${LOCALBASE}/bin/${_u:L}"
.endfor

.if !defined(NOPORTDOCS)
PORTDOCS=	README.txt
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	lmdemo.c Makefile.demo
.endif
PLIST_FILES=	include/levmar.h \
	lib/liblevmar.a \
	lib/liblevmar.so \
	lib/liblevmar.so.2

.if !(defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE))
PLIST_FILES+=	lib/liblevmar_p.a
.endif

post-extract:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.demo ${WRKSRC}/
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g' \
		-e 's+%%CFLAGS%%+${CFLAGS} -I${LOCALBASE}/include+g' \
		-e 's+%%LDFLAGS%%+${LDFLAGS} -L${LOCALBASE}/lib+g' \
		-e 's+%%BLAS%%+${BLAS}+g' \
		-e 's+%%LAPACK%%+${LAPACK}+g' \
			${WRKSRC}/Makefile.demo

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
