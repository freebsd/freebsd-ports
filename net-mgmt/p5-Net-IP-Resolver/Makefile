# New ports collection makefile for:	net-mgmt/p5-Net-IP-Resolver
# Date created:				24 February 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP-Resolver
PORTVERSION=	0.01
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Net::IP::Resolver - Resolve IPs to a particular network

BUILD_DEPENDS=	p5-Net-IP-Match-XS>=0.03:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS \
		p5-ExtUtils-AutoInstall>0:${PORTSDIR}/devel/p5-ExtUtils-AutoInstall
RUN_DEPENDS=	p5-Net-IP-Match-XS>=0.03:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-XS

PERL_CONFIGURE=	yes

MAN3=	Net::IP::Resolver.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
