# New ports collection makefile for:	p5-XML-RAI
# Date created:				2004-05-22
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	XML-RAI
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RSS Abstraction Interface

BUILD_DEPENDS=	${SITE_PERL}/XML/Elemental.pm:${PORTSDIR}/textproc/p5-XML-Elemental
RUN_DEPENDS=	${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/XML/Elemental.pm:${PORTSDIR}/textproc/p5-XML-Elemental

PERL_CONFIGURE=	yes

MAN3=	XML::RAI::Object.3 XML::RAI::Item.3 XML::RAI.3 XML::RAI::Image.3 \
	XML::RAI::Channel.3 XML::RSS::Parser::Element.3 XML::RSS::Parser.3 \
	XML::RSS::Parser::Characters.3 XML::RSS::Parser::Feed.3
.include <bsd.port.mk>
