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

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/ATLAS
NO_PACKAGE=	"It is better to compile at the target machine."
NO_CDROM=	"It is better to compile at the target machine."

do-configure:
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} config < ${FILESDIR}/answer)

do-build:
	(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install arch=FreeBSD_GENERIC)
	(cd ${WRKSRC}; ${MKDIR} tmp ; \
			${CP} ${LOCALBASE}/lib/liblapack.a tmp ;\
			cd tmp ;\
			ar x liblapack.a ;\
			ar x ../lib/FreeBSD_GENERIC/liblapack.a ;\
			ar r ../lib/FreeBSD_GENERIC/libalapack.a *.o ;\
			ranlib ../lib/FreeBSD_GENERIC/libalapack.a )
do-install:
	@${MKDIR} ${PREFIX}/share/doc/atlas
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD_GENERIC/libatlas.a    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD_GENERIC/libcblas.a    ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD_GENERIC/libf77blas.a  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD_GENERIC/libtstatlas.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/FreeBSD_GENERIC/libalapack.a  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/atlas
.include <bsd.port.mk>
