# New ports collection makefile for:   dtdparse
# Date created:                29 January 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	dtdparse
PORTVERSION=	2.00
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dtdparse
DISTNAME=	SGML-DTDParse-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parse a DTD and produce an XML document that represents it

RUN_DEPENDS=	${SITE_PERL}/Text/DelimMatch.pm:${PORTSDIR}/textproc/p5-DelimMatch \
		${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MAN1=		dtddiff2html.1 dtdformat.1 dtddiff.1 dtdparse.1 dtdflatten.1
MAN3=		SGML::DTDParse::DTD.3 SGML::DTDParse.3 SGML::DTDParse::Util.3

.include <bsd.port.mk>
