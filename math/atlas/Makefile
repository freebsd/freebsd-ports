# New ports collection makefile for:	atlas
# Date created:		12 February 2001
# Whom:			Nakata Maho <chat95@mbox.kyoto-inet.or.jp>
#
# $FreeBSD$
#

PORTNAME=	atlas
PORTVERSION=	3.3.14
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	math-atlas
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

BUILD_DEPENDS=	${LOCALBASE}/lib/liblapack.a:${PORTSDIR}/math/lapack

IS_INTERACTIVE=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
NO_PACKAGE=	"It is better to compile at the target machine."
NO_CDROM=	"It is better to compile at the target machine."

do-configure:
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config)

do-build:
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=`cat ${WRKSRC}/ARCHNAME`)
	(cd ${WRKSRC}; ${MKDIR} tmp ; \
			${CP} ${LOCALBASE}/lib/liblapack.a tmp ;\
			cd tmp ;\
			ar x liblapack.a ;\
			ar x ../lib/`cat ${WRKSRC}/ARCHNAME`/liblapack.a ;\
			ar r ../lib/`cat ${WRKSRC}/ARCHNAME`/libalapack.a *.o ;\
			ranlib ../lib/`cat ${WRKSRC}/ARCHNAME`/libalapack.a )
do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/libatlas.a    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/libcblas.a    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/libf77blas.a  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/libtstatlas.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/`cat ${WRKSRC}/ARCHNAME`/libalapack.a  ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
