# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rocs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graph theory IDE for KDE 4

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT4=	script scripttools \
		moc_build qmake_build rcc_build uic_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
