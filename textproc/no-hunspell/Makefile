# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://alioth.debian.org/frs/download.php/2357/
PKGNAMEPREFIX=	no-
DISTNAME=	no_NO-pack2-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Norwegian (Nynorsk and Bokmaal) hunspell dictionaries

EXTRACT_SUFX=	.zip
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/nb_NO.aff \
		%%DATADIR%%/nb_NO.dic \
		%%DATADIR%%/nn_NO.aff \
		%%DATADIR%%/nn_NO.dic
PLIST_DIRSTRY=	%%DATADIR%%

post-extract:
	@${MKDIR} ${WRKSRC}
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/nb_NO.zip -C ${WRKSRC}/
	@${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${WRKDIR}/nn_NO.zip -C ${WRKSRC}/

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/nb_NO.aff ${WRKSRC}/nb_NO.dic \
		${WRKSRC}/nn_NO.aff ${WRKSRC}/nn_NO.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
