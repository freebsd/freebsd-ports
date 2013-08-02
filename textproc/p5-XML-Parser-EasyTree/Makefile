# ex:ts=8
# Ports collection makefile for:	XML::Parser::EasyTree
# Date created:			Oct 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	XML-Parser-EasyTree
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easier tree style for XML::Parser

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	XML::Parser::EasyTree.3

.include <bsd.port.mk>
