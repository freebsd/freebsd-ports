# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dejavu
PORTVERSION=	2.34
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-fonts-ttf-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

BUILD_DEPENDS=	${LOCALBASE}/bin/mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		${LOCALBASE}/bin/mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

OPTIONS_DEFINE=	DOCS LINKS
OPTIONS_DEFAULT=LINKS
OPTIONS_SUB=	yes
LINKS_DESC=	Install links of configuration files in conf.d

USES=		tar:bzip2

PLIST_SUB=	FCDIR=${FCDIR} FCDIR_LINKS=${FCDIR_LINKS} FONTSDIR=${FONTSDIR}
PORTDOCS=	README langcover.txt status.txt unicover.txt
SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

FCDIR?=		etc/fonts/conf.avail
FCDIR_LINKS=	${FCDIR:S|conf.avail|conf.d|}
FONTSDIR?=	lib/X11/fonts/${PORTNAME}

do-build:
	@cd ${WRKSRC}/ttf/ && ${LOCALBASE}/bin/mkfontscale
	@cd ${WRKSRC}/ttf/ && ${LOCALBASE}/bin/mkfontdir

do-install:
	cd ${STAGEDIR}${PREFIX}/ && ${MKDIR} ${FCDIR}/ ${FCDIR_LINKS}/ ${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${STAGEDIR}${PREFIX}/${FCDIR}/
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*dejavu*.conf .
	${INSTALL_DATA} ${WRKSRC}/ttf/fonts.* ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${PREFIX}/${FONTSDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
