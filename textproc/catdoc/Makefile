# New ports collection makefile for:   catdoc
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

PORTNAME=	catdoc
PORTVERSION=	0.91.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ice.ru/pub/vitus/
MASTER_SITE_SUBDIR=	support/catdoc

MAINTAINER=	brion@queeg.com

GNU_CONFIGURE=	yes
MAN1=		catdoc.1 xls2csv.1

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

.include <bsd.port.pre.mk>

.for i in 0 1 2 3
.if exists(${LOCALBASE}/bin/wish8.${i})
CONFIGURE_ARGS=	--with-wish=${LOCALBASE}/bin/wish8.${i}
RUN_DEPENDS=	${LOCALBASE}/bin/wish8.${i}:${PORTSDIR}/x11-toolkits/tk8${i}
.endif
.endfor

.include <bsd.port.post.mk>
