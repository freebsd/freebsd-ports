# New ports collection makefile for:	URI-Template
# Date created:				29 May 2007
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-Template
PORTVERSION=	0.15
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Object for handling URI templates

RUN_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		URI::Template.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
