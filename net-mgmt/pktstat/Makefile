# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pktstat
PORTVERSION=	1.8.5
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	freebsd@sosend.de
COMMENT=	Network traffic viewer

LICENSE=	PUBLIC_DOMAIN
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	The principal author has placed the entire work (source) in the public domain, thus choosing to not exercise copyright control over it.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	dleonard0
GH_TAGNAME=	46935839b

USES=		autoreconf
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
