# New ports collection makefile for:	avahi-autoipd
# Date created:				31 July 2007
# Whom:					Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net/avahi-autoipd/Makefile,v 1.1 2007/07/31 18:24:12 ahze Exp $
#

PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-autoipd

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IPv4LL network address configuration daemon

LIB_DEPENDS=	avahi-common.3:${PORTSDIR}/net/avahi-app

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-autoipd
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	autoipd

MAN8=		avahi-autoipd.8
USE_GNOME=	gnomehack gnometarget ltverhack intltool
PKGINSTALL=	${.CURDIR}/pkg-install

.include "${MASTERDIR}/Makefile"
