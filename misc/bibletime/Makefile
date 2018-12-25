# $FreeBSD$

PORTNAME=	bibletime
PORTVERSION=	2.11.2
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Open source Bible study tool

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to compile: btosismorphsegmentation.cpp.o: undefined reference to sword::SWOptionFilter::SWOptionFilter

LIB_DEPENDS=	libclucene-core.so:textproc/clucene \
		libsword.so:misc/sword

USES=		cmake qt:5 tar:xz ssl
USE_QT=		buildtools core dbus gui linguist_build network script svg \
		webkit xml qmake_build
.include <bsd.port.mk>
