# New ports collection makefile for:	www/p5-Catalyst-View-GraphViz
# Date created:				10 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

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

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::GraphView.3 \
	Catalyst::Helper::View::GraphViz.3 \
	Catalyst::View::GraphViz.3

.include <bsd.port.mk>
