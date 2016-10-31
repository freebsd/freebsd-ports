# Created by: Shen Chun-Hsing <statue@freebsd.netlab.cse.yzu.edu.tw>
# $FreeBSD$

PORTNAME=	stardict-rptts
PORTVERSION=	2.1.0
CATEGORIES=	textproc
MASTER_SITES=	SF/stardict-4/WyabdcRealPeopleTTS
DISTNAME=	WyabdcRealPeopleTTS
DIST_SUBDIR=	stardict

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Real People TTS for StarDict

NO_BUILD=	yes
USES=		tar:bzip2

do-install:
		${TAR} jxvf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} -C ${STAGEDIR}${PREFIX}/share

.include <bsd.port.mk>
