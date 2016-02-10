# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	libqtelegram-ae
PORTVERSION=	6.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-stable
CATEGORIES=	net-im

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Fork of libqtelegram by Aseman Team

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Aseman-Land
GH_PROJECT=	libqtelegram-aseman-edition

USES=		qmake:outsource
USE_QT5=	qmake_build buildtools_build core gui network multimedia
USE_LDCONFIG=	yes

.include <bsd.port.mk>
