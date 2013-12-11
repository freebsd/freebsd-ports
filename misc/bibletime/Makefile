# $FreeBSD$

PORTNAME=	bibletime
PORTVERSION=	2.9.2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Open source Bible study tool

LICENSE=	GPLv2

LIB_DEPENDS=	libsword.so:${PORTSDIR}/misc/sword \
		libclucene-core.so:${PORTSDIR}/textproc/clucene

USES=		cmake
USE_BZIP2=	yes
USE_OPENSSL=	yes
USE_QT4=	corelib dbus gui iconengines network phonon qtestlib script \
		svg webkit xml linguist_build moc_build qmake_build \
		rcc_build uic_build

NO_STAGE=	yes
.include <bsd.port.mk>
