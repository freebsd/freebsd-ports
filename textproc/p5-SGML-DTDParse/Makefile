# New ports collection makefile for:	p5-SGML-DTDParse
# Date created:	   			2006/07/11
# Whom:		   			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	SGML-DTDParse
PORTVERSION=	2.00
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse an SGML or XML DTD

BUILD_DEPENDS=	p5-DelimMatch>=1.05:${PORTSDIR}/textproc/p5-DelimMatch \
		p5-libxml>=0.08:${PORTSDIR}/textproc/p5-libxml \
		p5-XML-DOM>=1.44:${PORTSDIR}/textproc/p5-XML-DOM \
		p5-XML-Parser>=2.3:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		dtddiff2html.1 dtdformat.1 dtddiff.1 dtdparse.1 dtdflatten.1
MAN3=		SGML::DTDParse::DTD.3 SGML::DTDParse.3 SGML::DTDParse::Util.3

.include <bsd.port.mk>
