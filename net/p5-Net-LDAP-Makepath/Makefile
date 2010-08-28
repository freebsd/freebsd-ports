# New ports collection makefile for:	p5-Net-LDAP-Makepath
# Date created:		2008-06-24
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-Makepath
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Provides a methode for creating paths in LDAP simply

RUN_DEPENDS=	 ${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::Makepath.3

.include <bsd.port.mk>
