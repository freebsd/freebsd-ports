# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	CSS-Croco
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quick CSS parser

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libcroco-0.6.so:textproc/libcroco

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>
