# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	choqok
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www kde
MASTER_SITES=	SF/${PORTNAME}/Choqok/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE micro-blogging client

LICENSE=	GPLv3

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson \
		qoauth.1:${PORTSDIR}/net/qoauth

#BUILD_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kwebkitpart.so:${PORTSDIR}/www/kwebkitpart
#RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kwebkitpart.so:${PORTSDIR}/www/kwebkitpart

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	gui imageformats_run network \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USES=		cmake gettext
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
