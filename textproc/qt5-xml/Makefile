PORTNAME=	xml
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	textproc
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt SAX and DOM implementations

USES=		compiler:c++11-lang perl5 qmake:no_env qt-dist:5,base
USE_PERL5=	extract
USE_QT=		core qmake_build buildtools_build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-gui -no-xcb

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-configure:
.for d in src/xml
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

.include <bsd.port.mk>
