# New ports collection makefile for:   catdoc
# Version required:    0.90.1
# Date created:        11 November 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $Id: Makefile,v 1.5 1998/07/24 11:48:20 ache Exp $
#

DISTNAME=	catdoc-0.90.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.ice.ru/pub/vitus/

MAINTAINER=	brion@queeg.com

MAN1=		catdoc.1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wish=/usr/local/bin/wish8.0

.if !defined(LANG) || ${LANG} != ru_RU.KOI8-R
# Remove the below line to get Cyrillic code page support instead
CFLAGS+=	-DLATIN1=1
.endif

# the author seems to have included some .o files for us ;-)
pre-build:
	@cd $(WRKSRC); $(MAKE) -k clean

.include <bsd.port.mk>
