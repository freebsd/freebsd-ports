# New ports collection makefile for:	qca-tls
# Date created:				27 January 2004
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qca-tls
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://psi.affinix.com/beta/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	SSL/TLS plugin for Qt

HAS_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${X11BASE}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_FILES=	lib/plugins/crypto/libqca-tls.so

.include <bsd.port.mk>
