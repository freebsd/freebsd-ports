# $FreeBSD$

PORTNAME=	kig
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 interactive geometry application

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource
USE_QT4=	gui xml moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

MAN1=		kig.1

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=	PYTHON
PYTHON_DESC=	Support for Python scripting (requires Boost)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
LIB_DEPENDS+=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
.endif

.include <bsd.port.mk>
