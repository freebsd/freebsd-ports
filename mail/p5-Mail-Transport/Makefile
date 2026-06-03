PORTNAME=	Mail-Transport
PORTVERSION=	4.01
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKOV
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Mail Transfer Agents (MTAs)
WWW=		https://metacpan.org/release/Mail-Transport

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Log-Report>=1.42:devel/p5-Log-Report \
		p5-Mail-Message>=4.0:mail/p5-Mail-Message \
		p5-String-Print>=1.01:textproc/p5-String-Print

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
