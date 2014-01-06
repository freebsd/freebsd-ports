# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-View-Jemplate
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Jemplate files server

RUN_DEPENDS=	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Catalyst-Runtime>=5.50:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Jemplate>=0.19:${PORTSDIR}/www/p5-Jemplate
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
