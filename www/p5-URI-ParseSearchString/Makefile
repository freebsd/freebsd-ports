PORTNAME=	URI-ParseSearchString
PORTVERSION=	3.51
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse Apache referer logs and extract search engine query strings

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-URI>=0:net/p5-URI
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

PORTSCOUT=	skipv:3.441,3.442

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
