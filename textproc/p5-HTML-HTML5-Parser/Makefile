# New ports collection makefile for:	p5-HTML-HTML5-Parser
# Date created:				July 02 2010
# Whom:					jupengfei <jupengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-HTML5-Parser
PORTVERSION=	0.106
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	A named entity list for HTML parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Error>0:${PORTSDIR}/lang/p5-Error \
		p5-HTML-Encoding>=0.55:${PORTSDIR}/www/p5-HTML-Encoding \
		p5-HTML-HTML5-Entities>=0.001:${PORTSDIR}/textproc/p5-HTML-HTML5-Entities \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		p5-XML-LibXML>=1.60:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		HTML::HTML5::Parser.3 \
		HTML::HTML5::Parser::Error.3

.include <bsd.port.mk>
