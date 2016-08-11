# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	ardoise
PORTVERSION=	3.5
CATEGORIES=	x11-themes
MASTER_SITES=	https://github.com/obnosim/ardoise/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	cursor-
PKGNAMESUFFIX=	-theme
DISTFILES=	Ardoise_no_shadow_100.tar.gz Ardoise_no_shadow_75.tar.gz \
		Ardoise_no_shadow_87.tar.gz Ardoise_shadow_100.tar.gz \
		Ardoise_shadow_75.tar.gz Ardoise_shadow_87.tar.gz
DIST_SUBDIR=	${PKGBASE}/${PORTVERSION}

MAINTAINER=	lightside@gmx.com
COMMENT=	Ardoise X cursor theme

LICENSE=	CCBYNCSAv3
LICENSE_NAME=	Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported license
LICENSE_TEXT=	The license: ${LICENSE} (${LICENSE_NAME}) is standard, please read from the web:\
	http://creativecommons.org/licenses/by-nc-sa/3.0/
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/lib/X11/icons
PORTDATA=	*

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
