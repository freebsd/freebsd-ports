# New ports collection makefile for:	asp2php
# Date created:				Thu 29 Jun 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	asp2php
PORTVERSION=	0.76.23
CATEGORIES=	www
MASTER_SITES=	http://downloads.mikekohn.net/asp2php/

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Converts ASP scripts to PHP

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/a//}/src

WANT_GNOME=	yes
MAKE_ENV=	FLAGS="${CFLAGS}"
USE_REINPLACE=	yes

PLIST_FILES=	bin/asp2php

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PKGNAMESUFFIX=	-gtk
ALL_TARGET=	default gui
PLIST_FILES+=	bin/gtkasp2php
HAVE_GTK=	yes
.else
ALL_TARGET=	default
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC=|#CC=|g ; \
		 s| make| \$$\{MAKE\}|g ; \
		 s|`gtk-config|`\$$\{GTK_CONFIG\}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asp2php ${PREFIX}/bin
.if defined(HAVE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/gtkasp2php ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
