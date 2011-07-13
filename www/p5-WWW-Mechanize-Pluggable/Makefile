# New ports collection makefile for:	p5-WWW-Mechanize-Pluggable
# Date created:				04 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Pluggable
PORTVERSION=	1.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Custmomize WWW::Mechanize via plugins

RUN_DEPENDS=	p5-Data-Dump-Streamer>=0:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-HTML-Form>=1.038:${PORTSDIR}/www/p5-HTML-Form \
		p5-HTML-Parser>=2.28:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Daemon>=0:${PORTSDIR}/www/p5-HTTP-Daemon \
		p5-HTTP-Message>=1.3:${PORTSDIR}/www/p5-HTTP-Message \
		p5-URI>=1.25:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=1.66:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-libwww>=6:${PORTSDIR}/www/p5-libwww
TEST_DEPENDS=	p5-Test-Exception>=0.2:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	yes

MAN3=		WWW::Mechanize::Pluggable.3 \
		WWW::Mechanize::Pluggable::Design.3 \
		WWW::Mechanize::Plugin::Cookbook.3 \
		WWW::Mechanize::Plugin::HelloWorld.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
RUN_DEPENDS+=	p5-Module-Pluggable>=0:${PORTSDIR}/devel/p5-Module-Pluggable
.endif

.include <bsd.port.post.mk>
