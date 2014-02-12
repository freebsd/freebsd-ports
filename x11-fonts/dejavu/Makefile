# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dejavu
PORTVERSION=	2.34
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-fonts-ttf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

BUILD_DEPENDS=	${LOCALBASE}/bin/fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS=	${LOCALBASE}/bin/fc-cache:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	DOCS LINKS
LINKS_DESC=	Install links of configuration files in conf.d

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

.if ${PORT_OPTIONS:MLINKS}
FCDIR_LINKS=	${FCDIR_REL:S|conf.avail|conf.d|}
PLIST_SUB+=	FCDIR_LINKS="${FCDIR_LINKS}"
.else
PLIST_SUB+=	FCDIR_LINKS="@comment "
.endif

do-build:
	@cd ${WRKSRC}/ && ${LOCALBASE}/bin/mkfontscale
	@cd ${WRKSRC}/ && ${LOCALBASE}/bin/mkfontdir

do-install:
	${MKDIR} ${STAGEDIR}${FCDIR}/ ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${STAGEDIR}${FCDIR}/
	${INSTALL_DATA} ${WRKSRC}/fonts.* ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${FONTSDIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MLINKS}
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*dejavu*.conf .
.endif
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}/
	@${ECHO_MSG}

.include <bsd.port.mk>
