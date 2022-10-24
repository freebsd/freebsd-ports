PORTNAME=	Email-Simple-FromHandle
PORTVERSION=	0.055
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Perl library for making email objects from a filehandle
WWW=		https://github.com/rjbs/Email-Simple-FromHandle

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Simple>=0:mail/p5-Email-Simple \
		p5-IO-String>=0:devel/p5-IO-String

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
