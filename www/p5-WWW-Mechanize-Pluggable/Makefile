# New ports collection makefile for:	p5-WWW-Mechanize-Pluggable
# Date created:				04 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Pluggable
PORTVERSION=	1.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Custmomize WWW::Mechanize via plugins

BUILD_DEPENDS=	${SITE_PERL}/HTML/Form.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Module/Pluggable.pm:${PORTSDIR}/devel/p5-Module-Pluggable \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Data/Dump/Streamer.pm:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		${SITE_PERL}/Class/Inspector.pm:${PORTSDIR}/devel/p5-Class-Inspector \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	WWW::Mechanize::Pluggable.3 \
	WWW::Mechanize::Pluggable::Design.3 \
	WWW::Mechanize::Plugin::Cookbook.3 \
	WWW::Mechanize::Plugin::HelloWorld.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
