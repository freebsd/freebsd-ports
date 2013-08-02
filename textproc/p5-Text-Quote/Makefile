# ex:ts=8
# Ports collection makefile for:	Text::Quote
# Created by: ijliao
# $FreeBSD$

PORTNAME=	Text-Quote
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Quotes strings as required for perl to eval them back correctly

RUN_DEPENDS=	p5-Carp-Assert>=0.13:${PORTSDIR}/devel/p5-Carp-Assert
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Text::Quote.3

.include <bsd.port.mk>
