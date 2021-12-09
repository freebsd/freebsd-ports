PORTNAME=	kristall
DISTVERSIONPREFIX=	V
DISTVERSION=	git2021.11.20
CATEGORIES=	www

MAINTAINER=	mistresssilvara@hotmail.com
COMMENT=	Minimalistic Gemini/HTTP(S) browser

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcmark.so:textproc/cmark \
		libgumbo.so:devel/gumbo

USES=		compiler:c++17-lang desktop-file-utils gl iconv pkgconfig \
		qt:5 shared-mime-info ssl
USE_QT=		core gui multimedia network svg widgets buildtools_build \
		linguisttools_build qmake_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	MasterQ32
GH_TAGNAME=	6b39f244

MAKE_ARGS=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		QMAKE_COMMAND=${QMAKE} \
		QMAKE_CONFIG="external-gumbo-parser external-cmark"
ALL_TARGET=	${PORTNAME}

.include <bsd.port.mk>
