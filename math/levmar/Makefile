# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	levmar
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://users.ics.forth.gr/~lourakis/levmar/
EXTRACT_SUFX=	.tgz

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	GPL-licensed library implementing the Levenberg-Marquardt algorithm

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USES=		fortran

OPTIONS_DEFINE=	DOCS EXAMPLES PROFILE
PROFILE_DESC=	Build a profiling library

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libgoto2p.so)
WITH_BLAS?=	gotoblas
.elif exists(${LOCALBASE}/lib/libatlas.so)
WITH_BLAS?=	atlas
.else
WITH_BLAS?=	reference
.endif

.if ${WITH_BLAS} == "reference"
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.elif ${WITH_BLAS} == "gotoblas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
LIB_DEPENDS+=	libgoto2p.so:${PORTSDIR}/math/gotoblas
BLAS=		-lgoto2p
LAPACK=		-lgoto2p
.elif ${WITH_BLAS} == "atlas"
CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS=		-lptf77blas
LAPACK=		-lalapack -lptcblas
.endif

PORTDOCS=	README.txt
PORTEXAMPLES=	lmdemo.c Makefile.demo
PLIST_FILES=	include/levmar.h \
	lib/liblevmar.a \
	lib/liblevmar.so \
	lib/liblevmar.so.2

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE =	you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE	=	you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/liblevmar_p.a
.else
MAKE_ENV+=	NO_PROFILE=
.endif

post-extract:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.demo ${WRKSRC}/
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g' \
		-e 's+%%CFLAGS%%+${CFLAGS} -I${LOCALBASE}/include+g' \
		-e 's+%%LDFLAGS%%+${LDFLAGS}+g' \
		-e 's+%%BLAS%%+${BLAS}+g' \
		-e 's+%%LAPACK%%+${LAPACK}+g' \
			${WRKSRC}/Makefile.demo

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR})

test check: install
	@( cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} Makefile.demo \
	${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET} )
	${WRKSRC}/lmdemo

.include <bsd.port.post.mk>
