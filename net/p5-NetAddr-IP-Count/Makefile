# New ports collection makefile for:	net-mgmt/p5-NetAddr-IP-Count
# Date created:				29 March 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP-Count
PORTVERSION=	2.01
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	NetAddr::IP::Count - Count hosts in named subnets

BUILD_DEPENDS=	${SITE_PERL}/NetAddr/IP.pm:${PORTSDIR}/net-mgmt/p5-NetAddr-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		NetAddr::IP::Count.3

.include <bsd.port.mk>
