# $FreeBSD$

PORTNAME=	kpartsplugin
DISTVERSION=	0.0-${PORTDATE}
PORTREVISION=	4
CATEGORIES=	www kde
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~fischer/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTDATE}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Browser file viewer using KDE technology

USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USES=		cmake webplugin:native tar:bzip2
CMAKE_ARGS=	-DNSPLUGIN_INSTALL_DIR:PATH="${WEBPLUGIN_DIR}"

PORTDATE=	20120723

WEBPLUGIN_NAME=	# empty
WEBPLUGIN_FILES=lib${PORTNAME}.so

.include <bsd.port.mk>
