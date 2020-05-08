# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	Net-ARP
PORTVERSION=	1.0.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl extension for creating ARP packets

LICENSE=	GPLv2

TEST_DEPENDS=	p5-Net-Pcap>=0:net/p5-Net-Pcap

USES=		perl5 tar:tgz
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/ARP/ARP.so

.include <bsd.port.mk>
