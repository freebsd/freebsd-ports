# New ports collection makefile for:	qca-tls
# Date created:				27 January 2004
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qca-tls
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/ \
		http://psi.affinix.com/beta/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	SSL/TLS plugin for Qt

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${LOCALBASE} \
		--with-openssl-inc=${OPENSSLINC} --with-openssl-lib=${OPENSSLLIB}
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_DIRS=	lib/plugins/crypto
PLIST_FILES=	lib/plugins/crypto/libqca-tls.so

.include <bsd.port.mk>
