# New ports collection makefile for:	sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Sablot
PORTVERSION=	0.70
CATEGORIES=	textproc
MASTER_SITES=	http://download.gingerall.cz/sablot/

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv \
		expat.2:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION:E}

.include <bsd.port.mk>
