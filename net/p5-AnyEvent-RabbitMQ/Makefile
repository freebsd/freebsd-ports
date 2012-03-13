# New ports collection makefile for:	AnyEvent::RabbitMQ
# Date created:				29 Oct 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-RabbitMQ
PORTVERSION=	1.05
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	An asynchronous and multi channel Perl AMQP client

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-AnyEvent>=0:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Net-AMQP>=0:${PORTSDIR}/net/p5-Net-AMQP \
		p5-Devel-GlobalDestruction>=0:${PORTSDIR}/devel/p5-Devel-GlobalDestruction \
		p5-File-ShareDir>=0:${PORTSDIR}/devel/p5-File-ShareDir \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Readonly>=1.03:${PORTSDIR}/devel/p5-Readonly \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean

TEST_DEPENDS=	${RUN_DEPENDS}
PERL_CONFIGURE=	yes

MAN3=		AnyEvent::RabbitMQ.3 \
    		AnyEvent::RabbitMQ::Channel.3

.if defined(MAINTAINER_MODE)
regression-test: build
	cd ${WRKSRC} && ${MAKE} test
.endif

.include <bsd.port.mk>
