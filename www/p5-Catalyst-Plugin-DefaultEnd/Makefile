# Ports collection makefile for:	p5-Catalyst-Plugin-DefaultEnd
# Date created:				Nov 16, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-DefaultEnd
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/M/MR/MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sensible default end action

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	Catalyst::Plugin::DefaultEnd.3

.include <bsd.port.mk>
