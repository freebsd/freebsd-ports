# New ports collection makefile for:   dtdparse
# Date created:                29 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdparse
PORTVERSION=	2.00
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	SGML-DTDParse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse a DTD and produce an XML document that represents it

RUN_DEPENDS=	p5-DelimMatch>=0:${PORTSDIR}/textproc/p5-DelimMatch \
		p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM

USES=		perl5
USE_PERL5=	configure

MAN1=		dtddiff2html.1 dtdformat.1 dtddiff.1 dtdparse.1 dtdflatten.1
MAN3=		SGML::DTDParse::DTD.3 SGML::DTDParse.3 SGML::DTDParse::Util.3

.include <bsd.port.mk>
