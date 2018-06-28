# $FreeBSD$

PORTNAME=	ktp-approver
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging notifier

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt5 \
		libKTpCommonInternals.so:net-im/ktp-common-internals
RUN_DEPENDS=	${KDE_PREFIX}/bin/ktp-contactlist:net-im/ktp-contact-list

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm dbusaddons service i18n notifications
USE_QT=		core  dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
