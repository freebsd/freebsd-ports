# $FreeBSD$

PORTNAME=	Text-Haml
PORTVERSION=	0.990118
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Haml-parsing Perl extension

LICENSE=	ART20

BUILD_DEPENDS=	p5-URI>0:net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Data-Section-Simple>=0:devel/p5-Data-Section-Simple

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	yes

.include <bsd.port.mk>
