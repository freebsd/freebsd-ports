# New Ports Collection Makefile for:	p5-WWW-Mechanize-FormFiller
# Date created:				2004-07-07
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-FormFiller
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl framework to automate HTML forms

BUILD_DEPENDS=	${SITE_PERL}/Data/Random.pm:${PORTSDIR}/devel/p5-Data-Random \
		${SITE_PERL}/HTML/Form.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

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

FIX_USE_WARN=	lib/WWW/Mechanize/FormFiller.pm \
		lib/WWW/Mechanize/FormFiller/Value/Interactive.pm \
		t/embedded-WWW-Mechanize-FormFiller-Value-Interactive.t \
		t/embedded-WWW-Mechanize-FormFiller.t

FIX_USE_BASE=	lib/WWW/Mechanize/FormFiller/Value/Callback.pm \
		lib/WWW/Mechanize/FormFiller/Value/Default.pm \
		lib/WWW/Mechanize/FormFiller/Value/Fixed.pm \
		lib/WWW/Mechanize/FormFiller/Value/Interactive.pm \
		lib/WWW/Mechanize/FormFiller/Value/Keep.pm \
		lib/WWW/Mechanize/FormFiller/Value/Random/Chars.pm \
		lib/WWW/Mechanize/FormFiller/Value/Random/Date.pm \
		lib/WWW/Mechanize/FormFiller/Value/Random/Word.pm \
		lib/WWW/Mechanize/FormFiller/Value/Random.pm

.include <bsd.port.pre.mk>

post-patch:
.for _patch in ${FIX_USE_WARN}
	${MV}	${WRKSRC}/${_patch} ${WRKSRC}/${_patch}.orig
	${ECHO_CMD} 'BEGIN{if($$] < 5.006 && !$$::INC{"warnings.pm"}){ eval q|package warnings;sub import{$$^W=1}sub unimport{$$^W=0;1}$$::INC{"warnings.pm"}=1|}}' >${WRKSRC}/${_patch}
	${CAT}	${WRKSRC}/${_patch}.orig >>${WRKSRC}/${_patch}
	${RM}	${WRKSRC}/${_patch}.orig
.endfor
.for _patch in ${FIX_USE_BASE}
	${PERL} -pi -e 's/(use base .([\w:]+).;)/use $$2;$$1/' ${WRKSRC}/${_patch}
.endfor

.include <bsd.port.post.mk>
