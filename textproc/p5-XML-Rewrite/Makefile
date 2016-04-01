# Created by: Patrick Powell <papowell@astart.com>
# $FreeBSD$

PORTNAME=	XML-Rewrite
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	papowell@astart.com
COMMENT=	XML processing and rewriting

RUN_DEPENDS=	p5-Log-Report>=0.21:devel/p5-Log-Report \
		p5-XML-Compile-Cache>=0:textproc/p5-XML-Compile-Cache \
		p5-XML-LibXML>=1.70:textproc/p5-XML-LibXML
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
