# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Net-LDAP-AutoServer
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Automatically make some default decisions some LDAP server information

RUN_DEPENDS=	p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-DNS-RR-SRV-Helper>=0:dns/p5-Net-DNS-RR-SRV-Helper

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
