# New ports collection makefile for:	asp2php
# Date created:				Thu 29 Jun 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	asp2php
PORTVERSION=	0.75.12
CATEGORIES=	www
MASTER_SITES=	http://home.i1.net/~naken/asp2php/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}

WANT_GTK=	yes

.include <bsd.port.pre.mk>

.if defined(HAVE_GTK)
USE_GTK=	yes
ALL_TARGET=	all gtkasp2php
INSTALL_TARGET=	install install-gtk
PLIST_SUB+=	WANT_GTK=""
.else
PLIST_SUB+=	WANT_GTK="@comment "
.endif

pre-build:
	${PERL} -pi -e "s:gtk-config:${GTK_CONFIG}:g" ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
