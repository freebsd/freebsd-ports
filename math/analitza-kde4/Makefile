# $FreeBSD$

PORTNAME=	analitza
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	6
CATEGORIES=	math kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library from KDE Education project

LICENSE=	GFDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.DOC
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		cmake:outsource ncurses kde:4 readline tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	corelib dbus gui opengl svg xml \
		moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_LDCONFIG=	yes

.include <bsd.port.mk>
