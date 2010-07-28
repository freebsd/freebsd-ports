# New ports collection makefile for:	dejavu
# Date created:		Dec 23 2004
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-fonts/dejavu/Makefile,v 1.1 2006/10/13 23:29:09 ahze Exp $
#

PORTNAME=	dejavu
PORTVERSION=	2.31
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-fonts-ttf-${PORTVERSION}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
USE_BZIP2=	yes

FONTSDIR=	${PREFIX}/${FONTSDIR_REL}
FONTSDIR_REL?=	lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR_REL=${FONTSDIR_REL}
PORTDOCS=	README langcover.txt status.txt unicover.txt
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

do-install:
	@${MKDIR} ${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
