# $FreeBSD$

PORTNAME=	kig
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive geometry application

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	gui xml moc_build qmake_build rcc_build uic_build

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=	yes

PYTHON_DESC=	Support for Python scripting (requires Boost)
PYTHON_LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs

.include <bsd.port.mk>
