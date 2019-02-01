# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Pluggable
PORTVERSION=	1.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Custmomize WWW::Mechanize via plugins

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-HTML-Form>=1.038:www/p5-HTML-Form \
		p5-HTML-Parser>=2.28:www/p5-HTML-Parser \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-HTTP-Message>=1.30:www/p5-HTTP-Message \
		p5-Module-Pluggable>=0:devel/p5-Module-Pluggable \
		p5-URI>=1.25:net/p5-URI \
		p5-WWW-Mechanize>=1.66:www/p5-WWW-Mechanize \
		p5-libwww>=6.00:www/p5-libwww
TEST_DEPENDS=	p5-Test-Exception>=0.20:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
