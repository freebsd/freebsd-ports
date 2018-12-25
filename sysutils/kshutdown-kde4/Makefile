# $FreeBSD$

PORTNAME=	kshutdown
DISTVERSION=	4.2
PORTREVISION=	2
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KShutdown/${DISTVERSION}/
DISTNAME=	${PORTNAME}-source-${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Advanced shutdown utility for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		alias cmake compiler:c++0x gettext kde:4 qt:4 zip
USE_QT=		corelib dbus gui moc_build qmake_build rcc_build svg uic_build
USE_KDE=	automoc4 kdelibs workspace

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

# Make sure, we're building the KDE4 version.
CMAKE_ARGS=	-DKS_KF5:BOOL=FALSE \
		-DKS_PURE_QT:BOOL=FALSE

.include <bsd.port.mk>
