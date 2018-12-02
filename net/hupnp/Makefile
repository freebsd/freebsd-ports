# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hupnp
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}
DISTNAME=	herqq-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for building UPnP devices and control points

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/hupnp/LICENSE_LGPLv3.txt

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		gmake qmake qt:4 zip
USE_QT=		corelib network xml dbus gui \
		moc_build rcc_build uic_build
USE_CXXSTD=	gnu++98

QMAKE_ARGS=	"CONFIG+=DISABLE_AVTESTAPP DISABLE_TESTAPP"

.include <bsd.port.mk>
