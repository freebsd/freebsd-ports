# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	Net-Google-Code
PORTVERSION=	0.19
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Simple client library for Google code

BUILD_DEPENDS=	p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-Test-Mock-LWP>=0:devel/p5-Test-Mock-LWP \
		p5-Test-Simple>=0:devel/p5-Test-Simple
RUN_DEPENDS=	p5-Test-Simple>=0:devel/p5-Test-Simple \
		p5-Test-Mock-LWP>=0:devel/p5-Test-Mock-LWP \
		p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-File-MMagic>=0:devel/p5-File-MMagic \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-JSON>=0:converters/p5-JSON \
		p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-XML-FeedPP>=0:textproc/p5-XML-FeedPP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
