# $FreeBSD$

PORTNAME=	XML-SemanticDiff
PORTVERSION=	1.0002
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension for comparing XML documents

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	XML::SemanticDiff.3 \
	XML::SemanticDiff::BasicHandler.3

NO_STAGE=	yes
.include <bsd.port.mk>
