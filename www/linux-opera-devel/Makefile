# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	6.12.20030305
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/612/final/en/i386/static/ \
		ftp://ftp.opera.com/pub/opera/linux/612/final/en/i386/static/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/12./12-/}.1-static-qt.i386

MAINTAINER=	des@FreeBSD.org
COMMENT=	A blazingly fast, full-featured, standards-compliant browser

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXm.so.2:${PORTSDIR}/x11-toolkits/linux-openmotif \
		${LINUXBASE}/usr/lib/libpng.so.2:${PORTSDIR}/graphics/linux-png

USE_BZIP2=	yes
USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-install:
	(cd ${WRKSRC} && ./install.sh --prefix="${PREFIX}")

.include <bsd.port.mk>
