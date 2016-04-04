# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	POE-Component-Client-Ident
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	net perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for non-blocking ident lookups

BUILD_DEPENDS=	p5-POE>=0.9999:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-POE-Server-TCP>=0:devel/p5-Test-POE-Server-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
