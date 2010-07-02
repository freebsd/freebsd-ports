# New ports collection makefile for:	linuxlibertine
# Date created:				17 February 2008
# Whom:	      				Björn König <bkoenig@alpha-tierchen.de>
# $FreeBSD$
#

PORTNAME=	linuxlibertine
PORTVERSION=	4.4.1
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	LinLibertineFont-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Linux Libertine Open Fonts

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*//}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
NO_BUILD=	yes

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugs ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/GPL.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/OFL.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Readme-TEX.txt ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}

.include <bsd.port.mk>
