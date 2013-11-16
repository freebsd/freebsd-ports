# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.46
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	sv-
DISTNAME=	sv-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swedish hunspell dictionaries

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PROJECTHOST=	dsso

PLIST_FILES=	%%DATADIR%%/sv_FI.aff \
		%%DATADIR%%/sv_FI.dic \
		%%DATADIR%%/sv_SE.aff \
		%%DATADIR%%/sv_SE.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sv_SE.aff ${WRKSRC}/sv_SE.dic ${STAGEDIR}${DATADIR}/
	${LN} -s sv_SE.aff ${STAGEDIR}${DATADIR}/sv_FI.aff
	${LN} -s sv_SE.dic ${STAGEDIR}${DATADIR}/sv_FI.dic

.include <bsd.port.mk>
