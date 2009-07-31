# New ports collection makefile for:	qpxtool
# Date created:		23 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	qpxtool
PORTVERSION=	0.6.1
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A GUI for testing CD/DVD quality and transfer rate

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	3

MAKE_ARGS=	CC="${CC}" CXX="${CXX}"
MAKE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		QTDIR="${QT_PREFIX}"

USE_LDCONFIG=	yes
MANCOMPRESSED=	no
MAN8=		pxcontrol.8 pxfw.8

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -g -O2||; s|/usr/local|${PREFIX}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^LDLIBS.*+=/ s|$$| -lcam|' \
		${WRKSRC}/lib/qpxtransport/Makefile

.include <bsd.port.mk>
