PORTNAME=	OpenSPH
DISTVERSIONPREFIX=	v
DISTVERSION=	g20190519
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and graphical tools for running SPH and N-body simulations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang eigen:3 qmake qt:5
USE_GITLAB=	yes
GL_SITE=	https://gitlab.com
GL_ACCOUNT=	sevecekp
GL_PROJECT=	sph
GL_COMMIT=	06686fa7f7307bdf8c9261e55b9875aafa278a13
USE_WX=		3.1

QMAKE_SOURCE_PATH=	${WRKSRC}/sph.pro

BINARY_ALIAS=	wx-config=${LOCALBASE}/bin/wxgtk3u-3.1-config

PLIST_FILES=	bin/opensph-cli bin/opensph

do-install: # https://gitlab.com/sevecekp/sph/issues/2
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/cli/launcher/launcher ${STAGEDIR}${PREFIX}/bin/opensph-cli
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/gui/launcherGui/launcherGui ${STAGEDIR}${PREFIX}/bin/opensph

.include <bsd.port.mk>
