# New ports collection makefile for:	p5-HTML-ContentExtractor
# Date created:				2008-05-30
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-ContentExtractor
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Extract text contained within an HTML document

RUN_DEPENDS=	p5-HTML-Tree>=3.13:${PORTSDIR}/www/p5-HTML-Tree			\
		p5-HTML-TableExtract>=2.10:${PORTSDIR}/www/p5-HTML-TableExtract
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::ContentExtractor.3

.include <bsd.port.mk>
