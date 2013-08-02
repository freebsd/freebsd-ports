# New ports collection makefile for:	Lingua::EN::Summarize
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Lingua-EN-Summarize
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple tool for summarizing bodies of English text

BUILD_DEPENDS=	p5-HTML-Summary>=0:${PORTSDIR}/www/p5-HTML-Summary \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Lingua::EN::Filters.3 \
	Lingua::EN::Summarize.3

.include <bsd.port.mk>
