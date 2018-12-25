# $FreeBSD$

PORTNAME=	plasma-pass
DISTVERSION=	0.1.a.20181210
PORTREVISION=	1
CATEGORIES=	sysutils kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma applet for Pass password manager

RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++11-lib kde:5 qt:5
USE_KDE=	config coreaddons i18n itemmodels package plasma-framework service \
		ecm_build
USE_QT=		core dbus declarative gui network \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	kde
GH_TAGNAME=	e44fa13

.include <bsd.port.mk>
