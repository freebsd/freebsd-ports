# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/avahi-autoipd/Makefile,v 1.1 2007/07/31 18:24:12 ahze Exp $

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-autoipd

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IPv4LL network address configuration daemon

LIB_DEPENDS=	libavahi-common.so:net/avahi-app

USERS=		avahi-autoipd
GROUPS=		${USERS}

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-autoipd
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	autoipd

MANPAGES=	avahi-autoipd.8

.include "${MASTERDIR}/Makefile"
