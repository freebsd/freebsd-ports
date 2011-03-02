# New ports collection makefile for:	dejavu
# Date created:		Dec 23 2004
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-fonts/dejavu/Makefile,v 1.1 2006/10/13 23:29:09 ahze Exp $
#

PORTNAME=	dejavu
PORTVERSION=	2.33
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-fonts-ttf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	LINKS "Install links of configuration files in conf.d" off

NO_BUILD=	yes
USE_BZIP2=	yes

FCDIR=		${PREFIX}/${FCDIR_REL}
FCDIR_REL?=	etc/fonts/conf.avail
FONTSDIR=	${PREFIX}/${FONTSDIR_REL}
FONTSDIR_REL?=	lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FCDIR_REL=${FCDIR_REL} FONTSDIR_REL=${FONTSDIR_REL}
PORTDOCS=	README langcover.txt status.txt unicover.txt
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

.include <bsd.port.options.mk>

.if defined(WITH_LINKS)
FCDIR_LINKS=	${FCDIR_REL:S|conf.avail|conf.d|}
PLIST_SUB+=	FCDIR_LINKS="${FCDIR_LINKS}"
.else
PLIST_SUB+=	FCDIR_LINKS="@comment "
.endif

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${FCDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${FONTSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if defined(WITH_LINKS)
	cd ${PREFIX}/${FCDIR_LINKS} && ${LN} -fs ../conf.avail/*dejavu*.conf .
.endif

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
