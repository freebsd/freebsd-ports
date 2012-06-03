# New ports collection makefile for:	textproc/p5-Template-Plugin-Lingua-EN-Inflect
# Date created:				05 April 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-Plugin-Lingua-EN-Inflect
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Interface Template Toolkit to Lingua::EN::Inflect module

BUILD_DEPENDS=	p5-Lingua-EN-Inflect>=0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::Plugin::Lingua::EN::Inflect.3

.include <bsd.port.mk>
