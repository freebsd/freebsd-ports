# Created by: adam
# $FreeBSD$

PORTNAME=	pmf
PORTVERSION=	1.13.1
CATEGORIES=	net
MASTER_SITES=	http://ftp.ntua.gr/pub/net/mud/lpmud/clients/pmf/ \
		LOCAL/glarkin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Padrone's Mud Frontend

WRKSRC=		${WRKDIR}/pmfdir/src

USES=		readline

SUB_FILES=	pmfrc.default

OPTIONS_DEFINE=	DOCS EXAMPLES

post-build:
	@${LN} -sf .pmfrc ${WRKSRC}/../examples/dot.pmfrc 

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pmf ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/../system_dir && ${INSTALL_DATA} NEWS \
		${STAGEDIR}${DATADIR})
	(cd ${WRKDIR} && ${INSTALL_DATA} pmfrc.default \
		${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/../system_dir && ${COPYTREE_SHARE} helpfiles \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/../doc && ${INSTALL_DATA} * \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/../examples && ${INSTALL_DATA} * \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
