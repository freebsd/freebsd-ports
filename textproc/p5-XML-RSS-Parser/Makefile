# New ports collection makefile for:    p5-XML-RSS-Parser
# Date created:				21 Apr 2006
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-Parser
PORTVERSION=	4.0
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A liberal object-oriented parser for RSS feeds

RUN_DEPENDS=	${SITE_PERL}/XML/Elemental.pm:${PORTSDIR}/textproc/p5-XML-Elemental \
		${SITE_PERL}/Class/XPath.pm:${PORTSDIR}/devel/p5-Class-XPath \
		${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.0//}

MAN3=		XML::RSS::Parser.3 \
		XML::RSS::Parser::Characters.3 \
		XML::RSS::Parser::Element.3 \
		XML::RSS::Parser::Feed.3 \
		XML::RSS::Parser::Util.3

.include <bsd.port.mk>
