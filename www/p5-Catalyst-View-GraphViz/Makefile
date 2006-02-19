# New ports collection makefile for:	www/p5-Catalyst-View-GraphViz
# Date created:				10 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-GraphViz
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER= hideo@lastamericanempire.com
COMMENT=	Catalyst::View::GraphViz - GraphViz View Class

BUILD_DEPENDS=	${SITE_PERL}/Catalyst/Plugin/SubRequest.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
		${SITE_PERL}/GraphViz.pm:${PORTSDIR}/graphics/p5-GraphViz
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Helper::View::GraphView.3 \
	Catalyst::Helper::View::GraphViz.3 \
	Catalyst::View::GraphViz.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE= requires Perl 5.8. Install lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
