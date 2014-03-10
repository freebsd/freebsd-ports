# $FreeBSD$

PORTNAME=	hyphen
PORTVERSION=	2005.04.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}/
PKGNAMEPREFIX=	sv-
DISTNAME=	hyph_sv_SE-${PORTVERSION:C/\.//g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hyphenation rules

LICENSE=	LGPL21

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/hyph_sv_FI.dic \
		%%DATADIR%%/hyph_sv_SE.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/hyph_sv_SE.dic ${STAGEDIR}${DATADIR}/
	${LN} -s hyph_sv_SE.dic ${STAGEDIR}${DATADIR}/hyph_sv_FI.dic

.include <bsd.port.mk>
