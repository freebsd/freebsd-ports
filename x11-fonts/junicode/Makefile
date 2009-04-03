# New ports collection makefile for:	junicode
# Date created:		28 August 2006
# Whom:			Guerkan Senguen <gurkan@phys.ethz.ch>
#
# $FreeBSD$
#

PORTNAME=	junicode
PORTVERSION=	0.6.15
CATEGORIES=	x11-fonts
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode font for medievalists (Latin, IPA and Runic)

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

FONTSDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
	@${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pdf ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}

.include <bsd.port.mk>
