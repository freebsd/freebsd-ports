# New ports collection makefile for:	fribidi
# Date created:				17 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fribidi
PORTVERSION= 	0.1.12
CATEGORIES=	textproc devel
MASTER_SITES=	http://imagic.weizmann.ac.il/~dov/freesw/FriBidi/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	glib-1.3.1:${PORTSDIR}/devel/glib13

GLIB_CONFIG?=	${LOCALBASE}/bin/glib-config-2.0

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.mk>
