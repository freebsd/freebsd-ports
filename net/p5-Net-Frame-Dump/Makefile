# New ports collection makefile for:	Net-Frame-Dump
# Date created:	   08 Jan 2007
# Whom:		   Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Frame-Dump
PORTVERSION=	1.06
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Tcpdump like perl implementation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Bit/Vector.pm:${PORTSDIR}/math/p5-Bit-Vector \
		${SITE_PERL}/Net/Frame.pm:${PORTSDIR}/net/p5-Net-Frame \
    		p5-Net-Pcap>=0.12:${PORTSDIR}/net/p5-Net-Pcap \
    		p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::Frame::Dump.3 \
		Net::Frame::Dump::Offline.3 \
		Net::Frame::Dump::Online.3 \
		Net::Frame::Dump::Writer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
