# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-Pluggable
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Custmomize WWW::Mechanize via plugins

BUILD_DEPENDS=	p5-Data-Dump-Streamer>=0:devel/p5-Data-Dump-Streamer \
		p5-HTML-Form>=1.038:www/p5-HTML-Form \
		p5-HTML-Parser>=2.28:www/p5-HTML-Parser \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
		p5-HTTP-Message>=1.3:www/p5-HTTP-Message \
		p5-URI>=1.25:net/p5-URI \
		p5-WWW-Mechanize>=1.66:www/p5-WWW-Mechanize \
		p5-libwww>=6:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.2:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
