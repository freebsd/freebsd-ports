# Created by: Lowell Gilbert <lgfbsd@be-well.ilk.org>
# $FreeBSD$

PORTNAME=	isabella-ttf
PORTVERSION=	1.202
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.thibault.org/fonts/isabella/
DISTNAME=	Isabella-${PORTVERSION}-ttf

MAINTAINER=	lgfbsd@be-well.ilk.org
COMMENT=	Font by John Stracke based on the Isabella Breviary

BUILD_DEPENDS=	${MKFONTSCL_CMD}:${PORTSDIR}/x11-fonts/mkfontscale \
		${MKFONTDIR_CMD}:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Isabella
FONTDIR=	${PREFIX}/lib/X11/fonts/stracke
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}" \
		MKFONTSCL_CMD=${MKFONTSCL_CMD} \
		MKFONTDIR_CMD=${MKFONTDIR_CMD}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

NO_STAGE=	yes
do-install:
	${MKDIR} ${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTDIR}
	cd ${FONTDIR} && ${MKFONTSCL_CMD} && ${MKFONTDIR_CMD}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
