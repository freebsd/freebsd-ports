# New ports collection makefile for:		opera
# Date created:					November 5th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	opera
PORTVERSION=	6.10.20021029
CATEGORIES=	www
MASTER_SITES=	http://opera.online.no/unix/freebsd/610/final/en/static/ \
		ftp://ftp.opera.com/pub/opera/unix/freebsd/610/final/en/static/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/10./10-/}.1-static-qt.i386.freebsd

MAINTAINER=	des@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386
USE_XLIB=	yes

NO_BUILD=	yes
NO_FILTER_SHLIBS=yes

do-install:
	(cd ${WRKSRC} && ${SH} install.sh --prefix="${PREFIX}")

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

.include <bsd.port.post.mk>
