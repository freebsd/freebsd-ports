# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
PORTVERSION=	1.6.5
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/

MAINTAINER=	olivier@FreeBSD.org
COMMENT?=	Dynamic IP routing daemon (${FLAVOR:Uipv4:S/ip/IP/} version)

LICENSE=	GPLv2

FLAVORS=	ipv4 ipv6
ipv6_PKGNAMESUFFIX=	6

USES=		autoreconf bison gmake ncurses readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var

MAKE_JOBS_UNSAFE=	yes

USE_RC_SUBR=	${PKGBASE}

GROUPS=		birdvty

.if ${FLAVOR:U} == ipv6
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUB=	VER=6
.else
PLIST_SUB?=	VER=""
.endif

.include <bsd.port.mk>
