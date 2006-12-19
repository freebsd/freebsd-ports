# New ports collection makefile for:	Class-Gomor
# Date created:				17 May 2006
# Whom:					Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Write
PORTVERSION=	1.00
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	boumenot@gmail.com
COMMENT=	An interface to open and send raw frames to the network

BUILD_DEPENDS=	p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6 \
		p5-Net-Pcap>=0.14:${PORTSDIR}/net/p5-Net-Pcap
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Net::Write.3 \
	Net::Write::Layer.3 \
	Net::Write::Layer2.3 \
	Net::Write::Layer3.3 \
	Net::Write::Layer4.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=Needs perl 5.6.1 or higher, install lang/perl5.6 and try again.
.endif

.include <bsd.port.post.mk>
