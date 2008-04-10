# New ports collection makefile for:	junicode
# Date created:		28 August 2006
# Whom:			Guerkan Senguen <gurkan@phys.ethz.ch>
#
# $FreeBSD$
#

PORTNAME=	junicode
DISTVERSION=	0-6-12
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	Unicode font for medievalists (Latin, IPA and Runic)

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=	yes
NO_BUILD=	yes

PORTDOCS=	Junicode.pdf
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
WRKSRC=		${WRKDIR}

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}

.include <bsd.port.mk>
