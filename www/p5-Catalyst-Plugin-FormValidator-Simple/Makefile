# New ports collection makefile for:	www/p5-Catalyst-Plugin-FormValidator-Simple
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-FormValidator-Simple
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Validator for Catalyst with FormValidator::Simple

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-FormValidator>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator \
		p5-FormValidator-Simple>=0.28:${PORTSDIR}/textproc/p5-FormValidator-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Plugin::FormValidator::Simple.3

.include <bsd.port.mk>
