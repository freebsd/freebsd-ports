PORTNAME=	Net-Appliance-Session
PORTVERSION=	4.300005
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run command-line sessions to network appliances

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-IO-Prompt-Tiny>=0:devel/p5-IO-Prompt-Tiny \
		p5-Moo>=0:devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0:devel/p5-MooX-Types-MooseLike \
		p5-Net-CLI-Interact>=2.300003:net/p5-Net-CLI-Interact \
		p5-Term-ReadPassword>=0:devel/p5-Term-ReadPassword \
		p5-Text-Glob>=0:textproc/p5-Text-Glob \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
