# New ports collection Makefile for: vecfem
# Date created:		15 January 2001
# Whom:			Ralf Becker <ralf@akk.org>
#
# $FreeBSD$
#

PORTNAME=	vecfem
PORTVERSION=	3
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.massey.ac.nz/~lgrosz/vecfem/downloads/
DISTNAME=	vem

MAINTAINER=	ralf@akk.org
COMMENT=	Program to solve non-linear boundary value problems

.ifdef MPI
BUILD_DEPENDS=	${LOCALBASE}/mpich/bin/mpif77:${PORTSDIR}/net/mpich
.endif

NO_WRKSUBDIR=	YES
USE_GMAKE=	YES
EXTRACT_SUFFIX=	tar.gz
BUILD_WRKSRC=	${WRKDIR}/source
ALL_TARGET=

MAN7=		vemlst.7

pre-fetch:
.if !defined(MPI)
	@${ECHO_MSG} "Type \"make MPI=yes\" if you want MPI support"
.else
	@${ECHO_MSG} "Building ${PORTNAME}-${PORTVERSION} with MPI support"
.endif

.include <Makefile.inc>
.include <bsd.port.mk>
