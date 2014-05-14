# $FreeBSD$

PORTNAME=	2ping
PORTVERSION=	2.1.1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://www.finnie.org/software/2ping/

MAINTAINER=	gslin@gslin.org
COMMENT=	Bi-directional ping utility

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6

USES=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/2ping man/man1/2ping.1.gz

post-extract:
	@${REINPLACE_CMD} -e 's/2ping.1p/2ping.1/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
