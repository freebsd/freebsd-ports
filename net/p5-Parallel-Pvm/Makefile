# New ports collection makefile for:	Parallel-Pvm
# Date created:	   15 October 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Parallel-Pvm
PORTVERSION=	1.3.0
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Parallel
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl extension for the Parallel Virtual Machine (PVM)

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
PVM_ROOT=	${PREFIX}/lib/pvm
CONFIGURE_ENV=	PVM_ROOT="${PVM_ROOT}" PVM_ARCH="${PVM_ROOT}/lib/pvmgetarch"
CONFIGURE_ARGS=	INC="-I${PREFIX}/include"

MAN3=		Parallel::Pvm.3

NOT_FOR_ARCHS=	amd64 ia64

.include <bsd.port.mk>
