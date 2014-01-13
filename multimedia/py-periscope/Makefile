# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	periscope
PORTVERSION=	0.2.4
PORTREVISION=	2
CATEGORIES=	multimedia python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX} \
		periscope.desktop
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Subtitles searching module

LICENSE=	LGPL3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/BeautifulSoup.py:${PORTSDIR}/www/py-beautifulsoup32
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_GNOME=	desktopfileutils
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
NO_WRKSUBDIR=	yes
USES=	desktop-file-utils

OPTIONS_DEFINE=	UNRAR
UNRAR_DESC=	rar support (.rar) for compressed subtitles

OPTIONS_DEFAULT=	UNRAR

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR_WITHOUT_PREFIX:Q}

DESKTOPDIR_WITHOUT_PREFIX=	${DESKTOPDIR:S,^${PREFIX}/,,}

NO_STAGE=	yes
post-install:
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${DESKTOPDIR}

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUNRAR}
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.include <bsd.port.post.mk>
