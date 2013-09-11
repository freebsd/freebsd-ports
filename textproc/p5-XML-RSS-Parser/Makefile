# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XML-RSS-Parser
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A liberal object-oriented parser for RSS feeds

RUN_DEPENDS=	p5-XML-Elemental>=0:${PORTSDIR}/textproc/p5-XML-Elemental \
		p5-Class-XPath>=0:${PORTSDIR}/devel/p5-Class-XPath \
		p5-Class-ErrorHandler>=0:${PORTSDIR}/devel/p5-Class-ErrorHandler
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\.0//}

MAN3=		XML::RSS::Parser.3 \
		XML::RSS::Parser::Characters.3 \
		XML::RSS::Parser::Element.3 \
		XML::RSS::Parser::Feed.3 \
		XML::RSS::Parser::Util.3

.include <bsd.port.mk>
