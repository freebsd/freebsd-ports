# Created by: GomoR <netpkt@gomor.org>
# $FreeBSD$

PORTNAME=	Net-Packet
DISTVERSION=	3.27
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	netpkt@gomor.org
COMMENT=	Send and receive frames from layer 2 to layer 7

BUILD_DEPENDS=	p5-Bit-Vector>=6.4:math/p5-Bit-Vector \
		p5-Class-Gomor>=1.00:devel/p5-Class-Gomor \
		p5-Net-IPv6Addr>=0.2:net-mgmt/p5-Net-IPv6Addr \
		p5-Net-Libdnet>=0.01:net/p5-Net-Libdnet \
		p5-Net-Write>=1.00:net/p5-Net-Write \
		p5-Net-Pcap>=0.14:net/p5-Net-Pcap \
		p5-Socket6>=0.19:net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
