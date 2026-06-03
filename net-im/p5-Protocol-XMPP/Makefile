PORTNAME=	Protocol-XMPP
PORTVERSION=	0.007
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEAM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Protocol-level support for XMPP interaction
WWW=		https://metacpan.org/release/Protocol-XMPP

RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-XML-LibXML-SAX-ChunkParser>=0.00003:textproc/p5-XML-LibXML-SAX-ChunkParser
TEST_DEPENDS=	p5-curry>=0:devel/p5-curry \
		p5-Future>=0:devel/p5-Future \
		p5-Mixin-Event-Dispatch>=0:devel/p5-Mixin-Event-Dispatch \
		p5-Test-CheckDeps>=0:devel/p5-Test-CheckDeps \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
