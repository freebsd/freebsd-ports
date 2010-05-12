# New ports collection makefile for:    qtcurve-gtk2
# Date created:                         23 May 2008
# Whom:                                 Dmitry Klimov <lazyklimm@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qtcurve
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://home.freeuk.com/cpdrummond/ \
		http://craigd.wikispaces.com/file/view/
PKGNAMEPREFIX=	gtk2-
PKGNAMESUFFIX=	-theme
DISTNAME=	QtCurve-Gtk2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QtCurve GTK2 Theme Engine

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	gtk20

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800067
.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-*
.endif

post-extract:
.if ${OSVERSION} < 800067
	${CP} ${FILESDIR}/getline.h ${WRKSRC}/style
.if ${OSVERSION} < 701101
	${CP} ${FILESDIR}/getline_strndup.c ${WRKSRC}/style/getline.c
.else
	${CP} ${FILESDIR}/getline.c ${WRKSRC}/style/getline.c
.endif
.endif

.include <bsd.port.post.mk>
