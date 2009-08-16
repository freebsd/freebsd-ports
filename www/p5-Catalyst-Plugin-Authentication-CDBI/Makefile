# New ports collection makefile for:	www/p5-Catalyst-Plugin-Authentication-CDBI
# Date created:		2005-09-01
# Whom:			Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication-CDBI
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CDBI Authentication for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		${SITE_PERL}/Catalyst/Model/CDBI.pm:${PORTSDIR}/www/p5-Catalyst-Model-CDBI \
		${SITE_PERL}/Catalyst/Plugin/Session/FastMmap.pm:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-FastMmap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Catalyst::Plugin::Authentication::CDBI.3

.include <bsd.port.mk>
