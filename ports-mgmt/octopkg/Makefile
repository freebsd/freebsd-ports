PORTNAME=	octopkg
DISTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/aarnt/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Graphical front-end to the FreeBSD pkg-ng package manager
WWW=		https://tintaescura.com/projects/octopkg/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++17-lang desktop-file-utils gl qmake qt:6
USE_GL=		opengl
USE_LOCALE=	en_US.UTF-8
USE_QT=		base tools

PLIST_FILES=	bin/${PORTNAME} \
		lib/${PORTNAME}/${PORTNAME}-doas \
		share/applications/${PORTNAME}.desktop

post-patch:
	${REINPLACE_CMD} 's#/usr/lib#${PREFIX}/lib#' \
		${WRKSRC}/src/strconstants.cpp
	${REINPLACE_CMD} 's#/usr/local#${PREFIX}#' \
		${WRKSRC}/src/constants.h \
		${WRKSRC}/src/main.cpp

do-configure:
	cd ${WRKSRC} && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}
	cd ${WRKSRC}/doas && ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}
	cd ${WRKSRC}/doas && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/doas/${PORTNAME}-doas ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
