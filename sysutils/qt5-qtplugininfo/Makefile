# $FreeBSD$

PORTNAME=	qtplugininfo
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 plugin metadata dumper

USES=		qmake:outsource
USE_QT5=	core
QT_DIST=	tools

PLIST_FILES=	${QT_BINDIR}/qtplugininfo

# Similarly to x11/qt5-qev, it makes more sense to just run the build system
# from the qtplugininfo directory. If we run it from the top of the source tree, it
# will look for a lot more dependencies for other tools such as lupdate, which
# we do not really have to depend on.
WRKSRC_SUBDIR=	src/${PORTNAME}

post-patch:
	${CP} ${WRKSRC}/../../.qmake.conf ${WRKSRC}

.include <bsd.port.mk>
