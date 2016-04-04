# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	X500-DN
PORTVERSION=	0.29
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Handle X.500 DNs (Distinguished Names), parse, and format them

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
