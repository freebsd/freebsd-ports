# New ports collection makefile for:	p5-MasonX-Interp-WithCallbacks
# Date created:			May 21, 2004
# Whom:				Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	MasonX-Interp-WithCallbacks
PORTVERSION=	1.19
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Mason callback support via Params::CallbackRequest

BUILD_DEPENDS=	p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-Params-CallbackRequest>=0:${PORTSDIR}/devel/p5-Params-CallbackRequest
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		MasonX::Interp::WithCallbacks.3

.include <bsd.port.mk>
