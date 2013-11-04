# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2005.10.17
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	el-
DISTNAME=	hyph_el_GR-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Greek hyphenation rules

LICENSE=	LGPL21

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_el_CY.dic \
		%%DATADIR%%/hyph_el_GR.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_el_GR.dic ${STAGEDIR}${DATADIR}/
	${LN} -s hyph_el_GR.dic ${STAGEDIR}${DATADIR}/hyph_el_CY.dic

.include <bsd.port.mk>
