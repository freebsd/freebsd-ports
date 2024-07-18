PORTNAME=	OAI-Harvester
PORTVERSION=	1.20
PORTEPOCH=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:THB
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl module to harvest using the OAI protocol
WWW=		https://metacpan.org/release/OAI-Harvester \
		https://www.openarchives.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=1.30:net/p5-URI \
		p5-XML-SAX>=0.12:textproc/p5-XML-SAX \
		p5-XML-SAX-Base>=1.04:textproc/p5-XML-SAX-Base \
		p5-libwww>=2.0:www/p5-libwww
TEST_DEPENDS=	p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-XML-SAX-Writer>=0:textproc/p5-XML-SAX-Writer

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
