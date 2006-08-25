# New ports collection makefile for: gob2
# Date created: Aug 21, 2006
# Whom:         Alexey Mikhailov <karma@ez.pereslavl.ru>
#
# $FreeBSD$

PORTNAME=	gob2
PORTVERSION=	2.0.14
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gob2/2.0

MAINTAINER=	karma@ez.pereslavl.ru
COMMENT=	A preprocessor for making GObjects with inline C code

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USE_X_PREFIX=	yes
USE_ICONV=	yes

MAN1=		gob2.1

PLIST_FILES=	bin/gob2 share/aclocal/gob2.m4

.include <bsd.port.mk>
