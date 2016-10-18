# $FreeBSD$

PORTNAME=	analitza
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library from KDE Education project

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib gui opengl svg xml \
		moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_LDCONFIG=	yes

.include <bsd.port.mk>
