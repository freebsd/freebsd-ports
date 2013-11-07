# Created by: Nick Hilliard <nick@foobar.org>
# $FreeBSD$

PORTNAME=	MasonX-Request-WithApacheSession
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface to Apache::Session for HTML::Mason

BUILD_DEPENDS=	p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason \
		p5-Apache-Session-Wrapper>=0:${PORTSDIR}/www/p5-Apache-Session-Wrapper
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
