# $FreeBSD$

PORTNAME=	ZeroMQ
PORTVERSION=	0.23
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ZeroMQ2 wrapper for Perl

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

DEPRECATED=	Deprecated by upstream
EXPIRATION_DATE=2020-02-29

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libzmq.so:net/libzmq2 \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	p5-Task-Weaken>=0:devel/p5-Task-Weaken
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0.05:devel/p5-Test-Requires \
		p5-Test-TCP>=1.08:devel/p5-Test-TCP \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-JSON>=2.00:converters/p5-JSON

USES=		perl5 pkgconfig
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -i '' -e "s/lib => 'zmq',//" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
