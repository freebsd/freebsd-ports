# $FreeBSD$

PORTNAME=	bibletime
PORTVERSION=	2.11.2
PORTREVISION=	1
CATEGORIES=	misc kde
MASTER_SITES=	SF/${PORTNAME}/BibleTime%202/BibleTime%202%20source%20code

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	Open source Bible study tool

LICENSE=	GPLv2

LIB_DEPENDS=	libclucene-core.so:textproc/clucene \
		libsword.so:misc/sword

USES=		cmake compiler:c11 qt:5 tar:xz ssl
USE_QT=		buildtools core dbus gui linguist_build network script svg \
		webkit xml qmake_build
.include <bsd.port.mk>
