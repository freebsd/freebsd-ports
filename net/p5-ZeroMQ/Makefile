# Created by: Andrej Zverev <az@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ZeroMQ
PORTVERSION=	0.21
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	az@FreeBSD.org
COMMENT=	ZeroMQ2 wrapper for Perl

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
BUILD_DEPENDS=	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
LIB_DEPENDS=	zmq.1:${PORTSDIR}/devel/zmq \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-TCP>=1.08:${PORTSDIR}/devel/p5-Test-TCP \
		p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-JSON>=2.00:${PORTSDIR}/converters/p5-JSON

USES=		pkgconfig
MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	yes

MAN3=	\
	ZeroMQ::Raw.3 \
	ZeroMQ::Socket.3 \
	ZeroMQ::Context.3 \
	ZeroMQ.3 \
	ZeroMQ::Constants.3 \
	ZeroMQ::Poller.3 \
	ZeroMQ::Message.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.98:${PORTSDIR}/devel/p5-Test-Simple
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e "s/lib => 'zmq',//" ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
