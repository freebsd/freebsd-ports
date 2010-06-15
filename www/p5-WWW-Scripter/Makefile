# New ports collection makefile for:	p5-WWW-Scripter
# Date created:				26 Jan 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Scripter
PORTVERSION=	0.014
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module for scripting web sites that have scripts

RUN_DEPENDS=	p5-libwww>=5.829:${PORTSDIR}/www/p5-libwww \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-HTML-DOM>=0:${PORTSDIR}/www/p5-HTML-DOM \
		p5-CSS-DOM>=0:${PORTSDIR}/www/p5-CSS-DOM
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		WWW::Scripter::Location.3 WWW::Scripter.3 \
		WWW::Scripter::History.3 WWW::Scripter::WindowGroup.3

.include <bsd.port.mk>
