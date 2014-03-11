# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	XML-Compile-Cache
PORTVERSION=	1.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache Compiled XML Translators

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=0.19:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-Compile>=1.41:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-LibXML-Simple>=0.13:${PORTSDIR}/textproc/p5-XML-LibXML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-XML-Compile-Tester>=0.02:${PORTSDIR}/devel/p5-XML-Compile-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
