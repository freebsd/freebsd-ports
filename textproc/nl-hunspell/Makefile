PORTNAME=	hunspell
PORTVERSION=	2.20.23
CATEGORIES=	textproc
PKGNAMEPREFIX=	nl-

MAINTAINER=	office@FreeBSD.org
COMMENT=	Dutch hunspell dictionaries
WWW=		https://www.opentaal.org/producten/spellingcontrole/

LICENSE=	BSD3CLAUSE CC-BY-3.0
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	OpenTaal
GH_PROJECT=	opentaal-hunspell
GH_TAGNAME=	1c22bc3d61b2

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/nl.aff \
		${DATADIR}/nl.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/nl.aff ${STAGEDIR}${DATADIR}/nl.aff
	${INSTALL_DATA} ${WRKSRC}/nl.dic ${STAGEDIR}${DATADIR}/nl.dic

.include <bsd.port.mk>
