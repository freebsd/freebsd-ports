# New ports collection makefile for:	p5-XML-Compile-Cache
# Date created:		2009-01-11
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile-Cache
PORTVERSION=	0.92
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wenheping@gmail.com
COMMENT=	Cache Compiled XML Translators

BUILD_DEPENDS=	p5-Log-Report>=0.17:${PORTSDIR}/devel/p5-Log-Report \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-XML-Compile-Tester>=0.04:${PORTSDIR}/devel/p5-XML-Compile-Tester \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod
RUN_DEPENDS=	p5-Log-Report>=0.17:${PORTSDIR}/devel/p5-Log-Report \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		p5-XML-Compile-Tester>=0.04:${PORTSDIR}/devel/p5-XML-Compile-Tester \
		p5-XML-Compile>=0.96:${PORTSDIR}/textproc/p5-XML-Compile \
		p5-Test-Pod>=1.26:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=	XML::Compile::Cache.3

.include <bsd.port.mk>
