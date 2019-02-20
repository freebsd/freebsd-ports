# $FreeBSD$

PORTNAME=	plasma-pass
DISTVERSION=	1.0.0
MASTER_SITES=	KDE/stable/${PORTNAME}
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for Pass password manager

RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons i18n itemmodels package plasma-framework service \
		ecm_build
USE_QT=		core dbus declarative gui network \
		buildtools_build qmake_build

.include <bsd.port.mk>
