# New ports collection makefile for:	p5-Socket-Multicast6
# Date created:		2007-03-10
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Socket-Multicast6
PORTVERSION=	0.04
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Constructors and constants for IPv4/IPv6 multicast socket operations

RUN_DEPENDS=	p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6

PERL_MODBUILD=	yes

MAN3=		Socket::Multicast6.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
BUILD_DEPENDS+=	p5-ExtUtils-CBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-CBuilder
.endif

.include <bsd.port.post.mk>
