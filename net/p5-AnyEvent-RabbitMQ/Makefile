# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AnyEvent-RabbitMQ
PORTVERSION=	1.22
CATEGORIES=	net devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DLAMBLEY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous and multi channel Perl AMQP client

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-File-ShareDir-Install>=0.06:devel/p5-File-ShareDir-Install \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Devel-GlobalDestruction>=0:devel/p5-Devel-GlobalDestruction \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Net-AMQP>=0.06:net/p5-Net-AMQP \
		p5-Readonly>=1.03:devel/p5-Readonly \
		p5-namespace-clean>=0:devel/p5-namespace-clean
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
