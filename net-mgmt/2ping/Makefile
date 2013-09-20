# $FreeBSD$

PORTNAME=	2ping
PORTVERSION=	2.0
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://www.finnie.org/software/2ping/

MAINTAINER=	gslin@gslin.org
COMMENT=	A bi-directional ping utility

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6

USE_GMAKE=	yes
USES=		perl5

MAN8=		2ping.8 2ping6.8

NO_STAGE=	yes
.include <bsd.port.mk>
