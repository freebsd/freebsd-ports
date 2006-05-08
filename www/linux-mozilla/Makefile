# New ports collection makefile for:	linux-mozilla
# Date created:				2001-11-24
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	mozilla
PORTVERSION=	1.7.13
DISTVERSIONPREFIX=	i686-pc-linux-gnu-
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}${PORTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

.include "${.CURDIR}/../linux-seamonkey/Makefile.common"
.include <bsd.port.mk>
