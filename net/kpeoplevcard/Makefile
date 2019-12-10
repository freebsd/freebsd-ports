# $FreeBSD$

PORTNAME=	kpeoplevcard
DISTVERSION=	0.1
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Datasource plugin for KPeople to read vCard files

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	contacts coreaddons ecm i18n people
USE_QT=		core gui widgets \
		buildtools_build qmake_build

PLIST_FILES=	lib/cmake/KF5PeopleVCard/KF5PeopleVCardConfig.cmake \
		${QT_PLUGINDIR}/kpeople/datasource/KPeopleVCard.so

.include <bsd.port.mk>
