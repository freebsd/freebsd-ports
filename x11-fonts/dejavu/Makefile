# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dejavu
PORTVERSION=	2.35
DISTVERSIONPREFIX=	fonts-ttf-
CATEGORIES=	x11-fonts
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bitstream Vera Fonts clone with a wider range of characters

OPTIONS_DEFINE=	DOCS LINKS
OPTIONS_DEFAULT=LINKS
OPTIONS_SUB=	yes
LINKS_DESC=	Install links of configuration files in conf.d

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts tar:bzip2

PLIST_SUB=	FCDIR=${FCDIR} FCDIR_LINKS=${FCDIR_LINKS}
PORTDOCS=	README langcover.txt status.txt unicover.txt
SUB_FILES=	pkg-message

FCDIR?=		etc/fonts/conf.avail
FCDIR_LINKS=	${FCDIR:S|conf.avail|conf.d|}

do-install:
	cd ${STAGEDIR}${PREFIX}/ && ${MKDIR} ${FCDIR}/ ${FCDIR_LINKS}/ ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${STAGEDIR}${PREFIX}/${FCDIR}/
	cd ${STAGEDIR}${PREFIX}/${FCDIR_LINKS}/ && ${LN} -fs ../conf.avail/*dejavu*.conf .
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${STAGEDIR}${FONTSDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
