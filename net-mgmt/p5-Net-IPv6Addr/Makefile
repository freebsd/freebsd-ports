# New ports collection makefile for:	p5-Net-IPv6Addr
# Date created:				13 September 2001
# Whom:                			JJ Behrens <jj@nttmcl.com>
#
# $FreeBSD$
#

PORTNAME=	Net-IPv6Addr
PORTVERSION=	0.1
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	jj@nttmcl.com

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Net/IPv4Addr.pm:${PORTSDIR}/net/p5-Net-IPv4Addr \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Math/Base85.pm:${PORTSDIR}/math/p5-Math-Base85
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::IPv6Addr.3

.include <bsd.port.mk>
