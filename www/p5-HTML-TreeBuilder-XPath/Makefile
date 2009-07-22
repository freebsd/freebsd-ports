# New ports collection makefile for:	p5-HTML-TreeBuilder-XPath
# Date created:		2006-07-11
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-TreeBuilder-XPath
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Add XPath support to HTML::TreeBuilder

RUN_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-XML-XPathEngine>=0.12:${PORTSDIR}/textproc/p5-XML-XPathEngine
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::TreeBuilder::XPath.3

.include <bsd.port.mk>
