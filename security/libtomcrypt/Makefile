# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	1.09
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/
DISTNAME=	crypt-${PORTVERSION}

PATCH_SITES=	http://libtomcrypt.org/files/patch-1.09/
PATCHFILES=	lrw_process.c.patch

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

BROKEN=		"Does not fetch"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ARGS=	DESTDIR="${PREFIX}" LIBPATH="/lib" INCPATH="/include" \
		DATAPATH="${DOCSDIR}/pdf"
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	library

CFLAGS+=	-I${PREFIX}/include

OPTIONS=	DOCS "build documentation (depends on teTeX)" off \
		LIBTOMMATH "Use LibTomMath" on \
		TOMSFASTMATH "Use TomsFastMath" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_LIBTOMMATH) && defined(WITHOUT_TOMSFASTMATH)
IGNORE=	you must choose either LibTomMath or TomsFastMath (or both)
.endif

.if !defined(WITHOUT_LIBTOMMATH)
BUILD_DEPENDS+=	${LOCALBASE}/include/tommath.h:${PORTSDIR}/math/libtommath
CFLAGS+=	-DLTM_DESC
.endif

.if defined(WITH_TOMSFASTMATH)
BUILD_DEPENDS+=	${LOCALBASE}/include/tfm.h:${PORTSDIR}/math/tomsfastmath
CFLAGS+=	-DTFM_DESC
.endif

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.else
NOPORTDOCS=	yes
MAKE_ARGS+=	NODOCS=yes
.endif

.if defined(MAINTAINER_MODE)
test:	build
	@${ECHO_MSG} "Testing with -DUSE_TFM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_TFM" EXTRALIBS="-L${PREFIX}/lib -ltfm" ${GMAKE} test && ${WRKSRC}/test)

	@${ECHO_MSG} "Cleaning up test binary..."
	@${RM} ${WRKSRC}/test
	@${RM} ${WRKSRC}/demos/test.o

	@${ECHO_MSG} "Testing with -DUSE_LTM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_LTM" EXTRALIBS="-L${PREFIX}/lib -ltommath" ${GMAKE} test && ${WRKSRC}/test)
.endif
.include <bsd.port.post.mk>
