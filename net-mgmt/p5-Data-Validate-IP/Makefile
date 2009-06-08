# New ports collection makefile for:	net-mgmt/p5-Data-Validate-IP
# Date created:				02 January 2008
# Whom:					Tuc <freebsd-ports@t-b-o-h.net>
#
# $FreeBSD$
#

PORTNAME=	Data-Validate-IP
PORTVERSION=	0.10
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	freebsd-ports@t-b-o-h.net
COMMENT=	Common data validation methods for IPs

BUILD_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask
RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

PERL_CONFIGURE=	yes

MAN3=	Data::Validate::IP.3

.include <bsd.port.mk>
