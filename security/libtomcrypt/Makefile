# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	1.06
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/
DISTNAME=	crypt-${PORTVERSION}

PATCH_SITES=	http://www.libtomcrypt.org/files/patch-1.06/
PATCHFILES=	makefile.diff

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ARGS=	DESTDIR="${PREFIX}" LIBPATH="/lib" INCPATH="/include" \
		DATAPATH="${DOCSDIR}/pdf"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	library

CFLAGS+=	-I${PREFIX}/include

OPTIONS=	DOCS "build documentation (depends on teTeX)" off \
		LIBTOMMATH "Use LibTomMath" on \
		TOMSFASTMATH "Use TomsFastMath" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_LIBTOMMATH) && defined(WITHOUT_TOMSFASTMATH)
IGNORE=	You must choose either LibTomMath or TomsFastMath (or both)
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
INSTALL_TARGET=	install_lib
.endif

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC} && ${GMAKE} test && ${WRKSRC}/test)
.endif

.include <bsd.port.post.mk>
