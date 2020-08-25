# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tcpick
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Text-based TCP stream sniffer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/man/it/man8
	${MV} ${STAGEDIR}${PREFIX}/man/man8/tcpick_italian.8 ${STAGEDIR}${PREFIX}/man/it/man8/tcpick.8

.include <bsd.port.mk>
