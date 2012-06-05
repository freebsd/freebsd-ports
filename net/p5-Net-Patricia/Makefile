# New ports collection makefile for:	p5-Net-Patricia
# Date created:			Di  13 Mär 2001 19:37:25 CET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Patricia
PORTVERSION=	1.19
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for fast IP address lookups

RUN_DEPENDS=    p5-version>=0:${PORTSDIR}/devel/p5-version \
    		p5-Net-CIDR-Lite>=0:${PORTSDIR}/net/p5-Net-CIDR-Lite \
    		p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6

PERL_CONFIGURE=	YES

MAN3=		Net::Patricia.3

.include <bsd.port.mk>
