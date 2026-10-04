PORTNAME=	HTTP-Session2
DISTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for HTTP session management
WWW=		https://metacpan.org/release/HTTP-Session2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_RUN_DEPENDS=	p5-Cookie-Baker>0:www/p5-Cookie-Baker \
			p5-Crypt-CBC>0:security/p5-Crypt-CBC \
			p5-Crypt-Rijndael>0:security/p5-Crypt-Rijndael \
			p5-Crypt-SysRandom>0:security/p5-Crypt-SysRandom \
			p5-Data-MessagePack>0:devel/p5-Data-MessagePack \
			p5-Digest-HMAC>0:security/p5-Digest-HMAC \
			p5-Digest-SHA1>0:security/p5-Digest-SHA1 \
			p5-Mouse>0:devel/p5-Mouse

TEST_DEPENDS=	p5-Test-WWW-Mechanize-PSGI>0:devel/p5-Test-WWW-Mechanize-PSGI

USES=		perl5
USE_PERL5=	modbuildtiny

NO_ARCH=	YES

.include <bsd.port.mk>
