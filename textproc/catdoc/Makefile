# New ports collection makefile for:   catdoc
# Version required:    0.90.1
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id: Makefile,v 1.7 1998/12/27 04:21:58 billf Exp $
#

DISTNAME=	catdoc-0.90.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_TEX_CTAN} \
		ftp://ftp.ice.ru/pub/vitus/
MASTER_SITE_SUBDIR=	support/catdoc

MAINTAINER=	brion@queeg.com

GNU_CONFIGURE=	yes
MAN1=		catdoc.1

.if exists(${PREFIX}/bin/wish8.0)
CONFIGURE_ARGS+=	--with-wish=${PREFIX}/bin/wish8.0
.elseif exists(${PREFIX}/bin/wish8.1)
CONFIGURE_ARGS+=	--with-wish=${PREFIX}/bin/wish8.1
.else
CONFIGURE_ARGS+=	--disable-wordview
.endif

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

.include <bsd.port.mk>
