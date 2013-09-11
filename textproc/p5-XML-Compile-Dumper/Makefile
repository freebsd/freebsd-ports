# Created by: Patrick Powell <papowell@astart.com>
# $FreeBSD$

PORTNAME=	XML-Compile-Dumper
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	papowell@astart.com
COMMENT=	Dump Compiled XML Translators

BUILD_DEPENDS=	p5-Data-Dump-Streamer>=2.08:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
		p5-Log-Report>=0.19:${PORTSDIR}/devel/p5-Log-Report \
		p5-Test-Pod>=1.00:${PORTSDIR}/devel/p5-Test-Pod \
		p5-XML-Compile-Tester>=0.02:${PORTSDIR}/devel/p5-XML-Compile-Tester \
		p5-XML-Compile>=1.1:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-XML-LibXML-Simple>=0.13:${PORTSDIR}/textproc/p5-XML-LibXML-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	XML::Compile::Dumper.3

.include <bsd.port.mk>
