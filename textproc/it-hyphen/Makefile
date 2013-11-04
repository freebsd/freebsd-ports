# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2007.11.26
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	it-
DISTNAME=	hyph_it_IT-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Italian hyphenation rules

LICENSE=	LGPL21

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_it_CH.dic \
		%%DATADIR%%/hyph_it_IT.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_it_IT.dic ${STAGEDIR}${DATADIR}/
	${LN} -s hyph_it_IT.dic ${STAGEDIR}${DATADIR}/hyph_it_CH.dic

.include <bsd.port.mk>
