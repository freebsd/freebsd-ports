PORTNAME=	ZMQ-FFI
PORTVERSION=	1.17
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CALID
PKGNAMEPREFIX=	p5-

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Version agnostic Perl bindings for zeromq using FFI

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-FFI-CheckLib>=0.23:devel/p5-FFI-CheckLib \
		p5-FFI-Platypus>=0.84:devel/p5-FFI-Platypus
RUN_DEPENDS=	p5-FFI-CheckLib>=0.23:devel/p5-FFI-CheckLib \
		p5-FFI-Platypus>=0.84:devel/p5-FFI-Platypus \
		p5-Try-Tiny>=0.30:lang/p5-Try-Tiny \
		p5-Moo>=2.003004:devel/p5-Moo \
		p5-namespace-clean>=0.27:devel/p5-namespace-clean
LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		pkgconfig perl5
USE_PERL5=	configure

.include <bsd.port.mk>
