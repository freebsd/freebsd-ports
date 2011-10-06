# New ports collection makefile for:	p5-XML-LibXML-Simple
# Date created:		2009-04-21
# Whom:			TERAMOTO Masahiro <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-Simple
PORTVERSION=	0.91
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	XML::LibXML clone of XML::Simple::XMLin()

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-XML-LibXML>=1.64:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

TEST_DEPENDS=	p5-Test-Pod>=1.00:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		XML::LibXML::Simple.3

.include <bsd.port.mk>
