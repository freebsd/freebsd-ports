# New ports collection makefile for:	p5-HTML-SimpleLinkExtor
# Date created:			15 July 2004
# Whom:				Andrey Chernov <ache@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-SimpleLinkExtor
PORTVERSION=	1.09
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This is a simple HTML link extractor

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::SimpleLinkExtor.3

.include <bsd.port.mk>
