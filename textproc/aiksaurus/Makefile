# New ports collection makefile for:	aiksaurus
# Date created:				23 July 2004
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aiksaurus
PORTVERSION=	1.2.1
PORTREVISION?=	0
CATEGORIES?=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aiksaurus

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	A set of libraries and applications which provide a thesaurus

USE_GMAKE=	yes
USE_GNOME?=	gnomehack gnometarget
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS?=--without-gtk

.include <bsd.port.mk>
