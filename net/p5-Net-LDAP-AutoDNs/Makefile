# New ports collection makefile for:	p5-Net-LDAP-AutoDNs
# Date created:		2008-06-24
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-AutoDNs
PORTVERSION=	0.0.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Automatically make some default decisions some LDAP DNs and scopes

RUN_DEPENDS=	${SITE_PERL}/mach/BSD/Sysctl.pm:${PORTSDIR}/sysutils/p5-BSD-Sysctl

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::AutoDNs.3

.include <bsd.port.mk>
