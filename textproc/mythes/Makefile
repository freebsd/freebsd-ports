# New ports collection makefile for:	mythes
# Date created:		2011-06-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	1.2.1
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/MyThes/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple thesaurus library

LIB_DEPENDS=	hunspell-1.2.0:${PORTSDIR}/hungarian/hunspell

USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

CONFIGURE_ENV=	HUNSPELL_CFLAGS=-I${LOCALBASE}/include/hunspell \
	       	HUNSPELL_LIBS="-L${LOCALBASE}/lib -lhunspell-1.2"
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
