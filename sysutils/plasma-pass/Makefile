PORTNAME=	plasma-pass
DISTVERSION=	1.2.0
PORTREVISION=	1
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for Pass password manager

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liboath.so:security/oath-toolkit
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n itemmodels package plasma-framework service \
		ecm_build
USE_QT=		core dbus declarative gui network \
		buildtools_build qmake_build

.include <bsd.port.mk>
