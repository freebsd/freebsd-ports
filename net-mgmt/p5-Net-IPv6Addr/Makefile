# New ports collection makefile for:	p5-Net-IPv6Addr
# Date created:				13 September 2001
# Whom:                			JJ Behrens <jj@nttmcl.com>
#
# $FreeBSD$
#

PORTNAME=	Net-IPv6Addr
PORTVERSION=	0.2
CATEGORIES=	net-mgmt perl5 ipv6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv6 addresses

BUILD_DEPENDS=	${SITE_PERL}/Net/IPv4Addr.pm:${PORTSDIR}/net-mgmt/p5-Net-IPv4Addr \
		${SITE_PERL}/Math/Base85.pm:${PORTSDIR}/math/p5-Math-Base85
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::IPv6Addr.3

.include <bsd.port.mk>
