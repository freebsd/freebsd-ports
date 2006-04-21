# New ports collection makefile for:	p5-XML-RAI
# Date created:				2004-05-22
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-RAI
PORTVERSION=	1.3.01
PORTEPOCH=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RSS Abstraction Interface

RUN_DEPENDS=	${SITE_PERL}/XML/RSS/Parser.pm:${PORTSDIR}/textproc/p5-XML-RSS-Parser \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	XML::RAI.3 \
	XML::RAI::Channel.3 \
	XML::RAI::Image.3 \
	XML::RAI::Item.3 \
	XML::RAI::Object.3

.include <bsd.port.mk>
