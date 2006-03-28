# New ports collection makefile for:	net-mgmt/p5-Net-IP-Match-XS
# Date created:				24 February 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP-Match-XS
PORTVERSION=	0.03
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Efficiently match IP addresses against IP ranges

PERL_CONFIGURE=	yes

MAN3=	Net::IP::Match::XS.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
