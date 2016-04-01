# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Parallel-Pvm
PORTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the Parallel Virtual Machine (PVM)

BUILD_DEPENDS=	pvm:net/pvm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
PVM_ROOT=	${LOCALBASE}/lib/pvm
CONFIGURE_ENV=	PVM_ROOT="${PVM_ROOT}" PVM_ARCH="${PVM_ROOT}/lib/pvmgetarch"
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

NOT_FOR_ARCHS=	amd64 ia64

.include <bsd.port.mk>
