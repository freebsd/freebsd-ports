# New ports collection makefile for:	stp
# Date created:		2008-06-18
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stp
DISTVERSIONPREFIX=	ver-
DISTVERSION=	0.1
DISTVERSIONSUFFIX=	-11-18-2008
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}-fast-prover/${PORTNAME}-fast-prover/${PORTNAME}-ver-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A Decision Procedure for Bitvectors and Arrays

USE_BISON=	build
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

PLIST_FILES=	bin/stp \
		include/stp/c_interface.h \
		include/stp/fdstream.h \
		lib/libstp.a
PLIST_DIRS=	include/stp

do-configure:
	${ECHO_CMD} "PREFIX=${PREFIX}" > ${WRKSRC}/config.info
	${CP} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/stp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libstp.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/stp
	${INSTALL_DATA} ${WRKSRC}/c_interface/*.h ${PREFIX}/include/stp

.include <bsd.port.mk>
