# $FreeBSD$

PORTNAME=	ksecrets
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	security kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Secrets management infrastructure for KDE

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

IGNORE=		not ready for use, will be excluded from KDE SC 4.9

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs workspace
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
