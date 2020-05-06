# Created by: Eijiro Shibusawa <ej-sib@ice.uec.ac.jp>
# $FreeBSD$

PORTNAME=	levmar
PORTVERSION=	2.6
PORTREVISION=	14
CATEGORIES=	math
MASTER_SITES=	http://users.ics.forth.gr/~lourakis/levmar/

MAINTAINER=	phd_kimberlite@yahoo.co.jp
COMMENT=	GPL-licensed library implementing the Levenberg-Marquardt algorithm

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_LDCONFIG=	yes
USES=		fortran tar:tgz uidfix

OPTIONS_DEFINE=	DOCS EXAMPLES PROFILE
OPTIONS_SINGLE=	BLASLIB
OPTIONS_DEFAULT=	NETLIB
OPTIONS_SINGLE_BLASLIB=	ATLAS NETLIB OPENBLAS
PROFILE_DESC=	Build a profiling library

ATLAS_USES=	blaslapack:atlas
NETLIB_USES=	blaslapack:netlib
OPENBLAS_USES=	blaslapack:openblas

.include <bsd.port.pre.mk>

PORTDOCS=	README.txt
PORTEXAMPLES=	lmdemo.c Makefile.demo
PLIST_FILES=	include/levmar.h \
	lib/liblevmar.a \
	lib/liblevmar.so \
	lib/liblevmar.so.2

.if ${PORT_OPTIONS:MPROFILE}
.if defined(NOPROFILE) || defined(NO_PROFILE) || defined(WITHOUT_PROFILE)
IGNORE=		you have defined WITH_PROFILE, but have also defined\
WITHOUT_PROFILE, NOPROFILE, or NO_PROFILE
.elif !exists(/usr/lib/libc_p.a)
IGNORE=		you have chosen WITH_PROFILE, but have not installed the\
base system profiling libraries
.endif
PLIST_FILES+=	lib/liblevmar_p.a
.else
MAKE_ENV+=	WITHOUT_PROFILE=true
.endif

post-extract:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.dist
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.demo ${WRKSRC}/
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g' \
		-e 's+%%CFLAGS%%+${CFLAGS} -I${LOCALBASE}/include+g' \
		-e 's+%%LDFLAGS%%+${LDFLAGS}+g' \
		-e 's+%%BLAS%%+${BLASLIB}+g' \
		-e 's+%%LAPACK%%+${LAPACKLIB}+g' \
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
