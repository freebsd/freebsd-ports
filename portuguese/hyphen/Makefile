# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2004.04.15
PORTREVISION=	1
CATEGORIES=	portuguese textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
DISTNAME=	hyph_pt_PT-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Portuguese hyphenation rules

LICENSE=	LGPL21

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_pt_BR.dic \
		%%DATADIR%%/hyph_pt_PT.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_pt_PT.dic ${STAGEDIR}${DATADIR}/
	${LN} -s hyph_pt_PT.dic ${STAGEDIR}${DATADIR}/hyph_pt_BR.dic

.include <bsd.port.mk>
