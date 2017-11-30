# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	periscope
PORTVERSION=	0.2.4
PORTREVISION=	3
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

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:www/py-beautifulsoup32@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	distutils autoplist
NO_WRKSUBDIR=	yes
USES=		desktop-file-utils python:2.7

OPTIONS_DEFINE=	UNRAR
OPTIONS_DEFAULT=	UNRAR
UNRAR_RUN_DEPENDS=	unrar:archivers/unrar

PLIST_FILES=	share/applications/periscope.desktop

post-install:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
