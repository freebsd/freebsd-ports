# New ports collection makefile for:	asp2php
# Date created:				Thu 29 Jun 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	asp2php
PORTVERSION=	0.75.1
CATEGORIES=	www
MASTER_SITES=	http://home.i1.net/~naken/asp2php/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

.if defined(WANT_GTK)
LIB_DEPENDS+=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
.endif

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"
ALL_TARGET=	all
INSTALL_TARGET=	install

.if defined(WANT_GTK)
ALL_TARGET+=	gtkasp2php
INSTALL_TARGET+=install-gtk
PLIST_SUB+=	WANT_GTK=""
.else
PLIST_SUB+=	WANT_GTK="@comment "
.endif

pre-fetch:
	@${ECHO}
.if !defined(WANT_GTK)
	@${ECHO} "If you want the GTK frontend, define the WANT_GTK variable"
	@${ECHO} "in your make args.  For example:"
	@${ECHO}
	@${ECHO} "	make -DWANT_GTK"
.else
	@${ECHO} "Building with GTK frontend."
.endif
	@${ECHO}

.include <bsd.port.mk>
