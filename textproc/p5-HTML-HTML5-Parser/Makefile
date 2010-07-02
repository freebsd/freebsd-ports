# New ports collection makefile for:	p5-HTML-HTML5-Parser
# Date created:				July 02 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-HTML5-Parser
PORTVERSION=	0.101
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jupengfei@gmail.com
COMMENT=	A named entity list for HTML parser

BUILD_DEPENDS=	p5-Error>0:${PORTSDIR}/lang/p5-Error \
		p5-Test-Simple>0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-HTML-Encoding>=0.55:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>0:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		HTML::HTML5::Parser.3 \
		HTML::HTML5::Parser::NamedEntityList.3

.include <bsd.port.mk>
