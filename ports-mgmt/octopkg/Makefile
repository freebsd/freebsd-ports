# Created by: kmoore@FreeBSD.org

PORTNAME=	octopkg
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	ports-mgmt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front-end to the FreeBSD pkg-ng package manager

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmake compiler:c++11-lib qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	aarnt

USE_QT=		core concurrent declarative gui linguist network xml widgets \
		buildtools_build

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
