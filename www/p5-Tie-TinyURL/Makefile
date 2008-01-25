# New ports collection makefile for:	p5-Tie-TinyURL
# Date created:				2008/01/26
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Tie-TinyURL
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Tied interface to TinyURL.com

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Tie::TinyURL.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
