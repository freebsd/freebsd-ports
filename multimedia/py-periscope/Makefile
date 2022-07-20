PORTNAME=	periscope
PORTVERSION=	0.2.4
PORTREVISION=	4
CATEGORIES=	multimedia python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/periscope/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX} \
		periscope.desktop
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Subtitles searching module

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils python:3.6+
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	UNRAR
OPTIONS_DEFAULT=	UNRAR
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar

NO_WRKSUBDIR=	yes
PLIST_FILES=	share/applications/periscope.desktop
NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|from BeautifulSoup import|from bs4 import|' \
		${WRKSRC}/periscope/plugins/Podnapisi.py \
		${WRKSRC}/periscope/plugins/Subtitulos.py \
		${WRKSRC}/periscope/plugins/SubsWiki.py \
		${WRKSRC}/periscope/plugins/Addic7ed.py \
		${WRKSRC}/periscope/plugins/SubScene.py
	${REINPLACE_CMD} -e 's|import os, re, BeautifulSoup|import os, re, bs4|' \
		${WRKSRC}/periscope/plugins/TvSubtitles.py

pre-build:
	@${LOCALBASE}/bin/2to3-${PYTHON_VER} --no-diffs --nobackups --verbose --write \
		${WRKSRC}/

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
