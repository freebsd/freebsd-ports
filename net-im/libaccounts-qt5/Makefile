# Created by: Tobias C. Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	libaccounts-qt5
PORTVERSION=	1.13
PORTREVISION=	9
CATEGORIES=	net-im
MASTER_SITES=	https://drive.google.com/uc?export=download&id=0B8fX9XOwH_g4cTRCaktXNDRmMXM&dummy= \
		LOCAL/rakuco
DISTNAME=	accounts-qt-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper for SSO framework

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib
BUILD_DEPENDS=	doxygen:devel/doxygen

FETCH_BEFORE_ARGS=	-o ${DISTFILES}

USES=		compiler:c++11-lib qmake pathfix pkgconfig python qt:5 tar:bz2
USE_QT=		buildtools_build core qmake_build testlib xml

pre-configure:
	${REINPLACE_CMD} -e 's,$$$${INSTALL_LIBDIR},${LOCALBASE}/libdata,' \
		${WRKSRC}/common-pkgconfig.pri

.include <bsd.port.mk>
