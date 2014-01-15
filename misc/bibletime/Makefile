# $FreeBSD$

PORTNAME=	bibletime
PORTVERSION=	2.10.0
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open source Bible study tool

LICENSE=	GPLv2

LIB_DEPENDS=	clucene-core:${PORTSDIR}/textproc/clucene
RUN_DEPENDS=	${LOCALBASE}/lib/libsword-1.7.2.so:${PORTSDIR}/misc/sword17
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		cmake:outsource
USE_XZ=		yes
USE_OPENSSL=	yes
USE_QT4=	corelib dbus gui iconengines network phonon qtestlib script \
		svg webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build

.include <bsd.port.mk>
