# New ports collection makefile for:	kfile-torrent
# Date created:		Wed Dec 29 03:39:16 UTC 2004
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kfile-torrent
PORTVERSION=	0.6
CATEGORIES=	misc kde
MASTER_SITES=	http://grammarian.homelinux.net/torrent/
DISTNAME=	torrent-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Konqueror KFilePlugin to display info about BitTorrent .torrent files

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes

EXTRA_PATCHES= ${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure
#EXTRA_PATCHES=  ${PORTSDIR}/x11/kde3/files/extrapatch-old_configure

EXPIRATION_DATE=2005-04-31
DEPRECATED=	It will included on KDE 3.4 which should be released around March, 2005

.include <bsd.port.mk>
