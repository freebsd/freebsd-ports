# $FreeBSD$

PORTNAME=	2ping
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://www.finnie.org/software/2ping/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bi-directional ping utility

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Digest-CRC>=0:${PORTSDIR}/security/p5-Digest-CRC \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

PLIST_FILES=	bin/2ping \
		${SITE_MAN1}/2ping.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|2ping.1p|2ping.1|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
