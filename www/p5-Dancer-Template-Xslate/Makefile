# New ports collection makefile for:	Dancer-Template-Xslate
# Date created:		23 October 2011
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	Dancer-Template-Xslate
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RSIMOES
PKGNAMEPREFIX=	p5-

MAINTAINER=	magik@roorback.net
COMMENT=	Text::Xslate wrapper for Dancer

RUN_DEPENDS=	p5-Dancer>0:${PORTSDIR}/www/p5-Dancer \
		p5-Text-Xslate>0:${PORTSDIR}/textproc/p5-Text-Xslate
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Dancer::Template::Xslate.3

.include <bsd.port.mk>
