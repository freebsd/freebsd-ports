# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-LibXML-Cache
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Document cache for XML::LibXML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI \
		p5-XML-LibXML>=1.59:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.59:textproc/p5-XML-LibXSLT
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Touch>=0:devel/p5-File-Touch \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
