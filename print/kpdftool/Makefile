# New ports collection makefile for:	kpdftool
# Date created:				04 May 2006
# Whom:					Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$
#

PORTNAME=	kpdftool
PORTVERSION=	0.22
PORTREVISION=	3
CATEGORIES=	print kde
MASTER_SITES=	http://www.yuanjue.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to ease your PDF related work

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

BROKEN=		checksum mismatch
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ARGS+=	QTDIR=${QT_PREFIX}

do-configure:
	cd ${WRKSRC}; \
	${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

PLIST_FILES=	bin/kpdftool

.include <bsd.port.mk>
