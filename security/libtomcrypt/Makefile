# Ports collection makefile for:  libtomcrypt
# Date created:			  22 Jan 2004
# Whom:				  Yonatan <Yonatan@Xpert.com>
#
# $FreeBSD$
#

PORTNAME=	libtomcrypt
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://libtomcrypt.org/files/:source \
		http://libtomcrypt.org/files/patch-1.00/:patch
DISTFILES=	crypt-${PORTVERSION}.tar.bz2:source \
		ltc-1.00-001.tar.bz2:patch

MAINTAINER=	onatan@gmail.com
COMMENT=	Comprehensive, modular and portable cryptographic toolkit

EXTRA_PATCHES=	${WRKDIR}/src/pk/pkcs1/pkcs_1_oaep_encode.c.patch \
		${WRKDIR}/src/pk/pkcs1/pkcs_1_oaep_decode.c.patch \
		${WRKDIR}/src/misc/base64/base64_decode.c.patch \
		${WRKDIR}/src/headers/tomcrypt.h.patch \
		${WRKDIR}/makefile.shared.patch \
		${WRKDIR}/makefile.patch \
		${WRKDIR}/changes.patch \

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV=	PREFIX=${PREFIX} DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
ALL_TARGET=	library

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS+=	gs:${PORTSDIR}/print/ghostscript-gnu
.else
NOPORTDOCS=	yes
INSTALL_TARGET=	install_lib
.endif

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/demos/test && ${MAKE} test ${MAKE_ARGS} && ${WRKSRC}/demos/test/test)
.endif

.include <bsd.port.mk>
