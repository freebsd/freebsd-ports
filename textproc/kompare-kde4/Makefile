# $FreeBSD$

PORTNAME=	kompare
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	textproc kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Diff/Patch Frontend

LIB_DEPENDS=	libkomparediff2.so:textproc/libkomparediff2-kde4

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
