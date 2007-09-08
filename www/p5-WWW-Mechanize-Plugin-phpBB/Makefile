# New ports collection makefile for:	p5-WWW-Mechanize-Plugin-phpBB
# Date created:				04 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-Plugin-phpBB
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Screen scraper for phpBB installations

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize/Pluggable.pm:${PORTSDIR}/www/p5-WWW-Mechanize-Pluggable \
		${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	WWW::Mechanize::Plugin::phpBB.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
