# New ports collection makefile for:	linux-libtheora
# Date created:		17 September 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libtheora
DISTVERSION=	1.0alpha4-2
PORTREVISION=	2
CATEGORIES=	multimedia linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video codec

DEPRECATED=     deprecated please use linux-f[89]-libtheora
EXPIRATION_DATE=        2011-05-01

CONFLICTS=	linux-f8-libtheora-[0-9]* linux-f10-libtheora-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
AUTOMATIC_PLIST=yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-extract:
	@${RM} -rf ${WRKDIR}/usr/share

.include <bsd.port.mk>
