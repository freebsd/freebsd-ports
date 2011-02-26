# New ports collection makefile for:	Catalyst-Authentication-Store-LDAP
# Date created:	   20 February 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Authentication-Store-LDAP
PORTVERSION=	1.012
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Authentication from an LDAP Directory for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		p5-Catalyst-Plugin-Authentication>=0.10003:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Authentication::Store::LDAP.3 \
		Catalyst::Authentication::Store::LDAP::Backend.3 \
		Catalyst::Authentication::Store::LDAP::User.3

.include <bsd.port.mk>
