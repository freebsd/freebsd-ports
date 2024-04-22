PORTNAME=	Mail-DataFeed-Abusix
PORTVERSION=	2.20210112
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org
COMMENT=	Send SMTP transaction data to the Abusix transaction feed
WWW=		https://metacpan.org/release/Mail-DataFeed-Abusix

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Moo>0:devel/p5-Moo
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Perl-Critic>0:textproc/p5-Test-Perl-Critic

USES=		perl5
USE_PERL5=	configure

TEST_ENV=	AUTHOR_TESTING=1

NO_ARCH=	yes

PLIST_FILES=	${SITE_MAN3_REL}/Mail::DataFeed::Abusix.3.gz \
		${SITE_PERL_REL}/Mail/DataFeed/Abusix.pm

.include <bsd.port.mk>
