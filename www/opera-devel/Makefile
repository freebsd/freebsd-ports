# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	6.10.20021015
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/linux/610/beta1/en/static_freebsd/ \
		ftp://ftp.opera.com/pub/opera/linux/610/beta1/en/static_freebsd/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/10./10-/}.1-static-qt.i386.freebsd

MAINTAINER=	des@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
LIB_DEPENDS=	c_r.4:${PORTSDIR}/misc/compat4x

USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-install:
	(cd ${WRKSRC} && ${SH} install.sh --prefix="${PREFIX}")

.include <bsd.port.mk>
