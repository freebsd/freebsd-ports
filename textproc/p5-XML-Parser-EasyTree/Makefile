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
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easier tree style for XML::Parser

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Parser::EasyTree.3

.include <bsd.port.mk>
