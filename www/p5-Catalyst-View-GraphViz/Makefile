# Created by: Zach Thompson <hideo@lastamericanempire.com>
# $FreeBSD$

PORTNAME=	Catalyst-View-GraphViz
PORTVERSION=	0.05
PORTREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst::View::GraphViz - GraphViz View Class

BUILD_DEPENDS=	p5-Catalyst-Plugin-SubRequest>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
		p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
