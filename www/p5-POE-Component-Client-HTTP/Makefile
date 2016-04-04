# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-Client-HTTP
PORTVERSION=	0.9480
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RCAPUTO
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE component for non-blocking/concurrent HTTP queries

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-POE>=1.312:devel/p5-POE \
		p5-libwww>=0:www/p5-libwww \
		p5-URI>=1.37:net/p5-URI \
		p5-POE-Component-Client-Keepalive>=0.2710:net/p5-POE-Component-Client-Keepalive
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-POE-Server-TCP>=1.14:devel/p5-Test-POE-Server-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
