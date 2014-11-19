# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	periscope
PORTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	multimedia python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX} \
		periscope.desktop
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Subtitles searching module

LICENSE=	LGPL3

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	distutils autoplist
NO_WRKSUBDIR=	yes
USES=		desktop-file-utils python

OPTIONS_DEFINE=	UNRAR
UNRAR_DESC=	rar support (.rar) for compressed subtitles
UNRAR_RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar

OPTIONS_DEFAULT=	UNRAR

PLIST_FILES=	share/applications/periscope.desktop

post-install:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
