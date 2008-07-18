# New ports collection makefile for:	p5-Template-GD
# Date created:		22 June 2006
# Whom:			Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-GD
PORTVERSION=	2.66
CATEGORIES=	www textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Template Toolkit plugin to interface with GD modules

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Template::Plugin::GD.3 \
		Template::Plugin::GD::Constants.3 \
		Template::Plugin::GD::Graph::area.3 \
		Template::Plugin::GD::Graph::bars.3 \
		Template::Plugin::GD::Graph::bars3d.3 \
		Template::Plugin::GD::Graph::lines.3 \
		Template::Plugin::GD::Graph::lines3d.3 \
		Template::Plugin::GD::Graph::linespoints.3 \
		Template::Plugin::GD::Graph::mixed.3 \
		Template::Plugin::GD::Graph::pie.3 \
		Template::Plugin::GD::Graph::pie3d.3 \
		Template::Plugin::GD::Graph::points.3 \
		Template::Plugin::GD::Image.3 \
		Template::Plugin::GD::Polygon.3 \
		Template::Plugin::GD::Text.3 \
		Template::Plugin::GD::Text::Align.3 \
		Template::Plugin::GD::Text::Wrap.3

.include <bsd.port.mk>
