# Created by: Andreas Heil <ah@linux-hq.de>
# $FreeBSD$

PORTNAME=	XML-Generator
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ah@linux-hq.de
COMMENT=	Simple Perl module for generating XML documents

BUILD_DEPENDS=	p5-XML-DOM>=0:textproc/p5-XML-DOM
RUN_DEPENDS=	p5-XML-DOM>=0:textproc/p5-XML-DOM

TEST_DEPENDS=	p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

USES=		perl5
USE_PERL5=	configure

regression-test test:
	@(cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} test)

.include <bsd.port.mk>
