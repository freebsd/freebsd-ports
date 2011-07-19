# New ports collection makefile for:	mythes
# Date created:		2011-06-18
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/hunspell/MyThes/${PORTVERSION}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple thesaurus library

LIB_DEPENDS=	hunspell-1.3.0:${PORTSDIR}/textproc/hunspell

USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
