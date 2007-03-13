# New ports collection makefile for:	p5-Socket-Multicast6
# Date created:		2007-03-10
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Socket-Multicast6
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/N/NJ/NJH
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Constructors and constants for IPv4/IPv6 multicast socket operations

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6

PERL_CONFIGURE=	yes

MAN3=		Socket::Multicast6.3

.include <bsd.port.mk>
