# New ports collection makefile for:	Parallel-MPI
# Date created:	   06 March 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Parallel-MPI
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parallel
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl interface to the MPI message passing system

BUILD_DEPENDS=	${LOCALBASE}/mpich/bin/mpicc:${PORTSDIR}/net/mpich
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CC=		${PREFIX}/mpich/bin/mpicc
CONFIGURE_ARGS=	LD="${PREFIX}/mpich/bin/mpicc" INC="-I${PREFIX}/mpich/include"

MAN3=		Parallel::MPI.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not build on ${ARCH}"
.endif

.include <bsd.port.post.mk>
