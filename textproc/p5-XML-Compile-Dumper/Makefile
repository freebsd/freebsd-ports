# Created by: Patrick Powell <papowell@astart.com>
# $FreeBSD$

PORTNAME=	XML-Compile-Dumper
PORTVERSION=	0.13
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	papowell@astart.com
COMMENT=	Dump Compiled XML Translators

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Dump-Streamer>=2.08:devel/p5-Data-Dump-Streamer \
		p5-Log-Report>=0.19:devel/p5-Log-Report \
		p5-Test-Pod>=1.00:devel/p5-Test-Pod \
		p5-XML-Compile-Tester>=0.02:devel/p5-XML-Compile-Tester \
		p5-XML-Compile>=1.1:textproc/p5-XML-Compile \
		p5-XML-LibXML-Simple>=0.13:textproc/p5-XML-LibXML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
