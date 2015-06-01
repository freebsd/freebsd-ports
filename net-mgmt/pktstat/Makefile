# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pktstat
PORTVERSION=	1.8.5
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	freebsd@sosend.de
COMMENT=	Network traffic viewer

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	The principal author has placed the entire work (source) in the public domain, thus choosing to not exercise copyright control over it.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	dleonard0

USES=		autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} '/struct arphdr/d' ${WRKSRC}/ether.c
	@${REINPLACE_CMD} -e 's/IPPORT_USERRESERVED/IPPORT_RESERVED/' ${WRKSRC}/tcp.c

.include <bsd.port.mk>
