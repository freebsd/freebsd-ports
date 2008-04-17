# New ports collection makefile for:	p5-HTML-SimpleLinkExtor
# Date created:			15 July 2004
# Whom:				Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-SimpleLinkExtor
PORTVERSION=	1.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This is a simple HTML link extractor

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		linktractor.1
MAN3=		HTML::SimpleLinkExtor.3

.include <bsd.port.mk>
