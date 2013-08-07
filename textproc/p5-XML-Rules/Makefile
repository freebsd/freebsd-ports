# $FreeBSD$

PORTNAME=	XML-Rules
PORTVERSION=	1.16
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse XML and specify rules for individual tags

RUN_DEPENDS=	p5-XML-Parser>=2.00:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	XML::Rules.3

.include <bsd.port.mk>
