# New ports collection makefile for:	p5-XML-LibXML-Cache
# Date created:		2011-09-11
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-LibXML-Cache
PORTVERSION=	0.12
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Document cache for XML::LibXML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=1.59:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.59:${PORTSDIR}/textproc/p5-XML-LibXSLT
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Touch>=0:${PORTSDIR}/devel/p5-File-Touch \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

USE_PERL5=	configure
USES=		perl5

MAN3=		XML::LibXML::Cache.3 \
		XML::LibXML::Cache::Base.3 \
		XML::LibXSLT::Cache.3

.include <bsd.port.mk>
