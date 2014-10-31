# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ubuntu-font
PORTVERSION=	0.80
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://font.ubuntu.com/download/

DISTNAME=	${PORTNAME}-family-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Ubuntu font family

LICENSE=	UFL
LICENSE_FILE=	${WRKSRC}/LICENCE.txt
LICENSE_NAME=	Ubuntu Font License (UFL)
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		zip
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
