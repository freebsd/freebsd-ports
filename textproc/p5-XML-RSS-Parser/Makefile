# New ports collection makefile for:	p5-XML-RSS-Parser
# Date created:	 	04 Sep 2003
# Whom:			Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-Parser
PORTVERSION=	2.15
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A liberal object-oriented parser for RSS Feeds

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Class/XPath.pm:${PORTSDIR}/devel/p5-Class-XPath

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::Parser.3 \
		XML::RSS::Parser::Element.3 \
		XML::RSS::Parser::Feed.3

.include <bsd.port.mk>
