# $FreeBSD$

PORTNAME=	bibletime
PORTVERSION=	2.10.0
PORTREVISION=	4
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open source Bible study tool

LICENSE=	GPLv2

LIB_DEPENDS=	libclucene-core.so:${PORTSDIR}/textproc/clucene \
		libsword.so:${PORTSDIR}/misc/sword

USES=		cmake:outsource
USE_XZ=		yes
USE_OPENSSL=	yes
USE_QT4=	corelib dbus gui iconengines network phonon qtestlib script \
		svg webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build

.include <bsd.port.mk>
