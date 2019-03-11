# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	indic-ttf
PORTVERSION=	0.5.14
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	DEBIAN/pool/main/t/ttf-indic-fonts
PKGNAMESUFFIX=	-fonts
DISTNAME=	${PORTNAME:C|(.*)-(.*)|\2-\1|}${PKGNAMESUFFIX}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of truetype Indic fonts

WRKSRC=		${WRKDIR}/${DISTNAME:S|_|-|}

USES=		fonts
NO_BUILD=	yes

FONTSNAME=	indic-ttf
CONFAVLOC?=	etc/fonts/conf.avail
CONFAVAILDIR=	${PREFIX}/${CONFAVLOC}

PLIST_SUB=	CONFAVAILDIR=${CONFAVLOC}

SUB_FILES=	pkg-message
SUB_LIST=	CONFAVAILDIR=${CONFAVAILDIR}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ttf-*/*.ttf ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/debian/ttf-*${PKGNAMESUFFIX}.copyright \
		${STAGEDIR}${FONTSDIR}/
	${MKDIR} ${STAGEDIR}${CONFAVAILDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf-*/90-ttf-*.conf \
		${STAGEDIR}${CONFAVAILDIR}/

.include <bsd.port.mk>
