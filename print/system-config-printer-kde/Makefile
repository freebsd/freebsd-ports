# $FreeBSD$

PORTNAME=	system-config-printer-kde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeadmin-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 frontend for system-config-printer

RUN_DEPENDS=	system-config-printer:${PORTSDIR}/print/system-config-printer \
		${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		cupsd:${PORTSDIR}/print/cups-base

USE_KDE4=	kdehier kdelibs kdeprefix pykde4 pykdeuic4 automoc4
USE_PYTHON=	2.5+
USE_QT4=	qmake_build moc_build uic_build rcc_build
DISTINFO_FILE=	${PORTSDIR}/sysutils/kdeadmin4/distinfo
USE_XZ=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DINSTALL_SYSTEM_CONFIG_PRINTER:BOOL=ON \
		-DBUILD_kuser:BOOL=OFF # Avoid checking for kdepimlibs.

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	cd ${BUILD_WRKSRC} && ${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		system-config-printer-kde.py \
		cmake-modules/FindSystemConfigPrinter.py

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
