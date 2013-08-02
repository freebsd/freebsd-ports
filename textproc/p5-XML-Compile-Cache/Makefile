# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML-Compile-Cache
PORTVERSION=	0.99.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache Compiled XML Translators

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Log-Report>=0.19:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile>=1.2:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-LibXML-Simple>=0.13:${PORTSDIR}/textproc/p5-XML-LibXML-Simple
TEST_DEPENDS=	p5-Test-Pod>=1.00:${PORTSDIR}/devel/p5-Test-Pod \
		p5-XML-Compile-Tester>=0.02:${PORTSDIR}/devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

MAN3=		XML::Compile::Cache.3

.include <bsd.port.mk>
