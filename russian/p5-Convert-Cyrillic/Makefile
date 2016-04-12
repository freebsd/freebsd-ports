# Created by: Sergey Kandaurov <pluknet@gmail.com>
# $FreeBSD$

PORTNAME=	Convert-Cyrillic
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	russian converters perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	cyrillic-${PORTVERSION}

MAINTAINER=	pluknet@gmail.com
COMMENT=	Routines for converting from one Cyrillic charset to another

BUILD_DEPENDS=	p5-Unicode-Map8>=0:converters/p5-Unicode-Map8
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
