# New ports collection Makefile for:	liblrdf
# Date created:			26 April 2003
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	liblrdf
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://plugin.org.uk/releases/lrdf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for manipulating RDF files describing LADSPA plugins

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	raptor.2:${PORTSDIR}/textproc/raptor

USE_GNOME=	gnomehack gnometarget lthack
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
