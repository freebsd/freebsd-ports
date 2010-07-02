# New ports collection makefile for:	p5-Net-LDAP-AutoServer
# Date created:		2010-02-18
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	Net-LDAP-AutoServer
PORTVERSION=	0.2.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Automatically make some default decisions some LDAP server information

RUN_DEPENDS=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/DNS/RR/SRV/Helper.pm:${PORTSDIR}/dns/p5-Net-DNS-RR-SRV-Helper

PERL_CONFIGURE=	yes

MAN3=		Net::LDAP::AutoServer.3

.include <bsd.port.mk>
