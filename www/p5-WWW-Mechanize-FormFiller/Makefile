# New Ports Collection Makefile for:	p5-WWW-Mechanize-FormFiller
# Date created:				2004-07-07
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-FormFiller
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl framework to automate HTML forms

BUILD_DEPENDS=	p5-Data-Random>=0.05:${PORTSDIR}/devel/p5-Data-Random \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Form>=1.038:${PORTSDIR}/www/p5-HTML-Form
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WWW::Mechanize::FormFiller.3 \
	WWW::Mechanize::FormFiller::Value.3 \
	WWW::Mechanize::FormFiller::Value::Callback.3 \
	WWW::Mechanize::FormFiller::Value::Default.3 \
	WWW::Mechanize::FormFiller::Value::Fixed.3 \
	WWW::Mechanize::FormFiller::Value::Interactive.3 \
	WWW::Mechanize::FormFiller::Value::Keep.3 \
	WWW::Mechanize::FormFiller::Value::Random.3 \
	WWW::Mechanize::FormFiller::Value::Random::Chars.3 \
	WWW::Mechanize::FormFiller::Value::Random::Date.3 \
	WWW::Mechanize::FormFiller::Value::Random::Word.3

.include <bsd.port.mk>
