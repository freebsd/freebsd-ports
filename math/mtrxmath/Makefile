# New ports collection makefile for:	mtrxmath
# Date created:				09 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       	mtrxmath
PORTVERSION=		0.9.3
CATEGORIES=     	math
MASTER_SITES=		http://www.angelfire.com/linux/linuxjeff/mtrxmath/files/

MAINTAINER=		greid@ukug.uk.freebsd.org

LIB_DEPENDS=		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrxmath ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/README.mtrxmath

.include <bsd.port.mk>
