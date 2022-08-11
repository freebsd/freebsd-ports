PORTNAME=	Parallel-Pvm
PORTVERSION=	1.4.0
PORTREVISION=	4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the Parallel Virtual Machine (PVM)

LIB_DEPENDS=	libpvm3.so:net/pvm

USES=		perl5
USE_PERL5=	configure
PVM_ROOT=	${LOCALBASE}/lib/pvm
CONFIGURE_ENV=	PVM_ROOT="${PVM_ROOT}" PVM_ARCH="${PVM_ROOT}/lib/pvmgetarch"
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

.include <bsd.port.mk>
