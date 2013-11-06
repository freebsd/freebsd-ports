# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	choqok
PORTVERSION=	1.4
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/Choqok/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

LICENSE=	GPLv3

LIB_DEPENDS=	libqjson.so:${PORTSDIR}/devel/qjson \
		libqoauth.so:${PORTSDIR}/net/qoauth

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	gui imageformats_run network \
		moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USES=		cmake gettext
USE_LDCONFIG=	yes

.include <bsd.port.mk>
