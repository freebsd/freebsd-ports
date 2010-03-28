# New ports collection makefile for:	kpdftool
# Date created:				04 May 2006
# Whom:					Yuan, Jue <yuanjue@yuanjue.net>
# $FreeBSD$
#

PORTNAME=	kpdftool
PORTVERSION=	0.22
PORTREVISION=	5
CATEGORIES=	print kde
MASTER_SITES=	http://www.kde-apps.org/CONTENT/content-files/
DISTFILES=	33194-${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to ease your PDF related work

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_ZIP=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ARGS+=	QTDIR=${QT_PREFIX}
MAKE_JOBS_SAFE=	yes

do-configure:
	cd ${WRKSRC}; \
	${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

PLIST_FILES=	bin/kpdftool

.include <bsd.port.mk>
