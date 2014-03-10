# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20140302
CATEGORIES=	polish textproc
MASTER_SITES=	LOCAL/sunpoet/${PORTNAME}
DISTNAME=	sjp-myspell-pl-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Polish hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

USES=		zip
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/pl_PL.aff \
		%%DATADIR%%/pl_PL.dic
PLIST_DIRSTRY=	%%DATADIR%%

post-extract:
	@${MKDIR} ${WRKSRC}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/pl_PL.zip -C ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pl_PL.aff ${WRKSRC}/pl_PL.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
