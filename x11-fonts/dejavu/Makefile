# New ports collection makefile for:	dejavu
# Date created:		Dec 23 2004
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-fonts/dejavu/Makefile,v 1.1 2006/10/13 23:29:09 ahze Exp $
#

PORTNAME=	dejavu
DISTVERSION=	2.29
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-fonts-ttf-${DISTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_XORG=	x11
NO_BUILD=	yes
PORTDOCS=	README status.txt unicover.txt langcover.txt
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}/"
MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
