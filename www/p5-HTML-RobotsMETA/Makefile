# New ports collection makefile for:	p5-HTML-RobotsMETA
# Date created:		2008-01-29
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	HTML-RobotsMETA
PORTVERSION=	0.00004
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DM/DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Parse HTML For Robots Exclusion META Markup

BUILD_DEPENDS=	p5-HTML-Parser>=3:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::RobotsMETA.3 \
		HTML::RobotsMETA::Rules.3

.include <bsd.port.mk>
