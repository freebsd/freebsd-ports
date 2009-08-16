# New ports collection makefile for:	p5-WWW-Shorten-Bitly
# Date created:				May 7, 2009
# Whom:					Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-Bitly
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	Abstract interface to bit.ly, one of URL shortening sites

BUILD_DEPENDS=	p5-JSON-Any>=1.18:${PORTSDIR}/converters/p5-JSON-Any \
		p5-WWW-Shorten>=1.9:${PORTSDIR}/www/p5-WWW-Shorten \
		p5-XML-Simple>=2.18:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten::Bitly.3

.include <bsd.port.mk>
