# $FreeBSD$

PORTNAME=	ZeroMQ
PORTVERSION=	0.21
PORTREVISION=	3
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	ZeroMQ2 wrapper for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Task-Weaken>=0:devel/p5-Task-Weaken
RUN_DEPENDS=	p5-Task-Weaken>=0:devel/p5-Task-Weaken
LIB_DEPENDS=	libzmq.so:net/libzmq2 \
		libuuid.so:misc/e2fsprogs-libuuid
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0.05:devel/p5-Test-Requires \
		p5-Test-TCP>=1.08:devel/p5-Test-TCP \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-JSON>=2.00:converters/p5-JSON

USES=		pkgconfig perl5
MAKE_JOBS_UNSAFE=	yes
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' -e "s/lib => 'zmq',//" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
