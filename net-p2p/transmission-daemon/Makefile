# Created by: Mezz <mezz@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-daemon

MAINTAINER=	crees@FreeBSD.org
COMMENT=	A fast and lightweight daemon BitTorrent client

RUN_DEPENDS=	${GEN_RUN_DEPENDS}

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	daemon

USE_RC_SUBR=	transmission
USERS=		transmission
GROUPS=		transmission

EXTRA_CONF_ARGS=--disable-cli \
		--enable-daemon \
		--without-gtk \
		--disable-mac \
		--disable-nls

MAN1=		transmission-daemon.1 transmission-remote.1

.include "${MASTERDIR}/Makefile"
