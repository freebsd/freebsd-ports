# New ports collection makefile for:	arpack
# Date created:         31 Jan 2003
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	arpack
PORTVERSION=	96
CATEGORIES=	math
MASTER_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz patch.tar.Z

PATCH_SITES=	http://www.caam.rice.edu/software/ARPACK/SRC/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Argand Library (serial version)

DIST_SUBDIR=	arpack

WRKSRC=		${WRKDIR}/ARPACK
ALL_TARGET=	lib

BUILD_DEPENDS=  ${LOCALBASE}/bin/f2c:${PORTSDIR}/lang/f2c

MAKE_ENV=	HOME=${WRKSRC}
INSTALLS_SHLIB=	yes
USE_REINPLACE= yes

.include <bsd.port.pre.mk>

pre-patch:
	@(cd ${WRKSRC}; tar -xzf ${DISTDIR}/${DIST_SUBDIR}/patch.tar.Z)

post-patch:
	@${REINPLACE_CMD} -e 's+%FC%+${FC}+g;' ${WRKSRC}/ARmake.inc
	@${REINPLACE_CMD} -e 's+%FFLAGS%+${FFLAGS}+g;' ${WRKSRC}/ARmake.inc

do-install:
	${INSTALL} ${WRKSRC}/libarpack.a ${PREFIX}/lib
	(${MKDIR} ${WRKSRC}/include ;\
	  cd ${WRKSRC}/include ;\
	  f2c -C++ -P  ${WRKSRC}/SRC/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/BLAS/*.f ;\
	  f2c -C++ -P  ${WRKSRC}/LAPACK/*.f ;\
	  ${CAT} *.P | ${GREP} -v :ref: > arpack.h)
	${INSTALL_DATA} ${WRKSRC}/include/arpack.h ${PREFIX}/include

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} $(PREFIX)/share/doc/arpack
	-${GZIP_CMD} ${GZIP} ${WRKSRC}/DOCUMENTS/ex-*.doc
	${CP} $(WRKSRC)/DOCUMENTS/ex-*.doc.gz $(PREFIX)/share/doc/arpack/
.endif

.include <bsd.port.post.mk>
