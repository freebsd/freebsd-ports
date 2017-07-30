# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-XPath
PORTVERSION=	1.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Modules for parsing and evaluating XPath statements

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-XML-Parser>=2.23:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Path-Tiny>=0.076:devel/p5-Path-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502501
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
