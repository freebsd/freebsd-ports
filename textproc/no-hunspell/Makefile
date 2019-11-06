# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	https://alioth.debian.org/frs/download.php/file/3764/
PKGNAMEPREFIX=	no-
DISTNAME=	no_NO-pack2-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Norwegian (Nynorsk and Bokmaal) hunspell dictionaries

BROKEN=		unfetchable

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/nb_NO.aff \
		%%DATADIR%%/nb_NO.dic \
		%%DATADIR%%/nn_NO.aff \
		%%DATADIR%%/nn_NO.dic

post-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -xf ${WRKDIR}/nb_NO.zip --directory ${WRKSRC}
	@${TAR} -xf ${WRKDIR}/nn_NO.zip --directory ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/nb_NO.aff ${WRKSRC}/nb_NO.dic \
		${WRKSRC}/nn_NO.aff ${WRKSRC}/nn_NO.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
