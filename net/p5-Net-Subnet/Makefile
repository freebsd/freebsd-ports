# New ports collection makefile for:	p5-Net-Subnet
# Date created:		2011-10-06
# Whom:			Henk van Oers <hvo.pm@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	Net-Subnet
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Fast IP-in-subnet matcher for IPv4 and IPv6, CIDR or mask

LICENSE=	ART10

BUILD_DEPENDS=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS=	p5-Socket6>=0.23:${PORTSDIR}/net/p5-Socket6

PERL_CONFIGURE=	yes

MAN3=		Net::Subnet.3

.include <bsd.port.mk>
