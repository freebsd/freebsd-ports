# Ports collection makefile for:	p5-Catalyst-Plugin-Authentication-Store-Htpasswd
# Date created:				Dec 12, 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Authentication-Store-Htpasswd
PORTVERSION=	0.020
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/N/NU/NUFFIN
PKGNAMEPREFIX=	p5-
DISTNAME=       ${PORTNAME}-0.02

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Use .htpasswd with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0.01:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Authen-Htpasswd>=0.13:${PORTSDIR}/security/p5-Authen-Htpasswd
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.1+

MAN3=	Catalyst::Plugin::Authentication::Store::Htpasswd::User.3 \
	Catalyst::Plugin::Authentication::Store::Htpasswd.3 \
	Catalyst::Plugin::Authentication::Store::Htpasswd::Backend.3

.include <bsd.port.mk>
