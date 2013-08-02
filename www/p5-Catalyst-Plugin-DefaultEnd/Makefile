# Ports collection makefile for:	p5-Catalyst-Plugin-DefaultEnd
# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-DefaultEnd
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sensible default end action

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.2000:${PORTSDIR}/www/p5-Catalyst-Runtime
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	Catalyst::Plugin::DefaultEnd.3

.include <bsd.port.mk>
