# New ports collection makefile for:	p5-Parse-Flex
# Date created:				30 May 2006
# Whom:	      				Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Parse-Flex
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	The Fastest Lexer in the West

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		${SITE_PERL}/${PERL_ARCH}/XSLoader.pm:${PORTSDIR}/devel/p5-XSLoader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Parse::Flex.3 Parse::Flex::Generate.3

.include <bsd.port.mk>
