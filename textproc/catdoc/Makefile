# New ports collection makefile for:   catdoc
# Version required:    0.90.1
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id: Makefile,v 1.6 1998/12/22 03:03:31 jseger Exp $
#

DISTNAME=	catdoc-0.90.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ice.ru/pub/vitus/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	brion@queeg.com

GNU_CONFIGURE=	yes
MAN1=		catdoc.1

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

.include <bsd.port.mk>
