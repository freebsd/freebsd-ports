# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	IO-Socket-INET6
PORTVERSION=	2.69
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SHLOMIF
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Perl module with object interface to AF_INET6 domain sockets

BUILD_DEPENDS=	p5-Socket6>=0.12:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS=	p5-Socket6>=0.12:${PORTSDIR}/net/p5-Socket6

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
