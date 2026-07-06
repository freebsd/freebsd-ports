PORTNAME=	CGI-Session
PORTVERSION=	4.49
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MARKSTOS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for persistent session management
WWW=		https://metacpan.org/release/CGI-Session

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Crypt-SysRandom>=0:security/p5-Crypt-SysRandom
TEST_DEPENDS=	p5-CGI-Session>=0:www/p5-CGI-Session \
		p5-CGI-Simple>=0:www/p5-CGI-Simple \
		p5-CGI>=0:www/p5-CGI \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DB \
		p5-FreezeThaw>=0:devel/p5-FreezeThaw

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
