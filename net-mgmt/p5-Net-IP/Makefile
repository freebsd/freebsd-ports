# New ports collection makefile for:   p5-Net-IP
# Date created:                30 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP
PORTVERSION=	1.21
CATEGORIES=	net-mgmt perl5 ipv6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension for manipulating IPv4/IPv6 addresses

PERL_CONFIGURE=	yes

MAN3=		Net::IP.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
post-patch:
	@${PERL} -pi -e '$$_ = "" if m|use 5.008|' ${WRKSRC}/Makefile.PL
.endif
.include <bsd.port.post.mk>
