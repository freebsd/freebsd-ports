# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asp2php
PORTVERSION=	0.76.26
CATEGORIES=	www
MASTER_SITES=	http://downloads.mikekohn.net/asp2php/

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Program to convert ASP scripts to PHP

LICENSE=	GPLv2

WANT_GNOME=	yes
MAKE_ARGS=	CC="${CC}" FLAGS="${CFLAGS}"

PLIST_FILES=	bin/asp2php

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}
USE_GNOME=	gtk12
PKGNAMESUFFIX=	-gtk
ALL_TARGET=	default gui
PLIST_FILES+=	bin/gtkasp2php
HAVE_GTK=	yes
.else
ALL_TARGET=	default
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -E \
		's|cd (.+) && make|$$(MAKE) -C \1| ; \
		 s|`gtk-config|`\$$\{GTK_CONFIG\}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asp2php ${PREFIX}/bin
.if defined(HAVE_GTK)
	${INSTALL_PROGRAM} ${WRKSRC}/gtkasp2php ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
