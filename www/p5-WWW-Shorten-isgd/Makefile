# New ports collection makefile for:	p5-WWW-Shorten-isgd
# Date created:				May 18, 2009
# Whom:					Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten-isgd
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	max@FreeBSD.org
COMMENT=	Abstract interface to is.gd, one of URL shortening sites

BUILD_DEPENDS=	p5-WWW-Shorten>=1.97:${PORTSDIR}/www/p5-WWW-Shorten
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten::isgd.3

.include <bsd.port.mk>
