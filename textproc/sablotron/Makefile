# New ports collection makefile for:	sablotron
# Date created:		13 Nov 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Sablot
PORTVERSION=	0.71
CATEGORIES=	textproc
MASTER_SITES=	http://download-2.gingerall.cz/download/sablot/

MAINTAINER=	skv@protey.ru

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv \
		expat.2:${PORTSDIR}/textproc/expat2

INSTALLS_SHLIB=	yes

SHLIB_MAJOR=	66
PLIST_SUB+=	SHLIB_MAJOR="${SHLIB_MAJOR}"

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
AUTOMAKE_ARGS=	-a
USE_LIBTOOL=	yes

pre-patch:
		@${PERL} -pi -e \
		's!(?<=libsablot_la_LDFLAGS = -version-info )(\d+):(\d+):\1!${SHLIB_MAJOR}:$$1:${SHLIB_MAJOR}!;' \
		${WRKSRC}/src/engine/Makefile.am

.include <bsd.port.mk>
