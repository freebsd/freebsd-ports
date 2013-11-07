# Created by: Rod Taylor <ports@rbt.ca>
# $FreeBSD$

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

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
