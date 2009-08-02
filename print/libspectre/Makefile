# New ports collection makefile for:	libspectre
# Date created:		2008-03-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/print/libspectre/Makefile,v 1.2 2008/03/13 16:30:50 ahze Exp $

PORTNAME=	libspectre
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://libspectre.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small library for rendering Postscript documents

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnomeprefix ltverhack
USE_GHOSTSCRIPT=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_GHOSTSCRIPT_GNU)
IGNORE=	Port will not work with ghostscript-gnu, please do not define WITH_GHOSTSCRIPT_GNU
.endif

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^ghostscript-gnu-[0-9]*'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: ghostscript-gnu installed, please deinstall ghostscript-gnu"; \
		${ECHO_CMD} "and use ghostscript-gpl. Make sure you don't have WITH_GHOSTSCRIPT_GNU"; \
		${ECHO_CMD} "or GHOSTSCRIPT_PORT defined."; \
		${FALSE}; \
	fi

.include <bsd.port.mk>
