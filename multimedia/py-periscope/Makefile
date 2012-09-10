# New ports collection makefile for:	periscope
# Date created:		Sun Jul 24 20:23:58 UTC 2011
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	periscope
PORTVERSION=	0.2.4
PORTREVISION=	1
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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=3.2.0:${PORTSDIR}/www/py-beautifulsoup32
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_GNOME=	desktopfileutils
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install
NO_WRKSUBDIR=	yes

OPTIONS=	UNRAR "Enable support for rar (.rar) compressed subtitles" on

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR_WITHOUT_PREFIX:Q}

DESKTOPDIR_WITHOUT_PREFIX=	${DESKTOPDIR:S,^${PREFIX}/,,}

post-install:
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${DESKTOPDIR}
	@-${LOCALBASE}/bin/update-desktop-database

.include <bsd.port.pre.mk>

# unrar (.rar) support
.if !defined(WITHOUT_UNRAR)
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.include <bsd.port.post.mk>
