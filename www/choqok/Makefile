# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	choqok
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/Choqok/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqjson.so:devel/qjson \
		libqoauth.so:net/qoauth \
		libtelepathy-qt4.so:net-im/telepathy-qt4

USES=		cmake gettext kde:4 tar:xz
USE_KDE=	attica automoc4 kdelibs
USE_QT4=	gui imageformats_run network \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
