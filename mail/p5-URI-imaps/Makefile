# New ports collection makefile for:	mail/p5-URI-imaps
# Date created:				30 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-imaps
PORTVERSION=	1.01
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Support IMAPS URI

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	URI::imaps.3

.include <bsd.port.mk>
