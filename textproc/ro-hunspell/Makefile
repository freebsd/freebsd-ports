# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	3.3.8
CATEGORIES=	textproc
MASTER_SITES=	SF/rospell/Romanian%20dictionaries/dict-${PORTVERSION}/
PKGNAMEPREFIX=	ro-
DISTNAME=	ro_RO.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Romanian hunspell dictionaries

LICENSE=	LGPL21 GPLv2 MPL
LICENSE_COMB=	dual

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/ro_RO.aff \
		%%DATADIR%%/ro_RO.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ro_RO.aff ${WRKSRC}/ro_RO.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
