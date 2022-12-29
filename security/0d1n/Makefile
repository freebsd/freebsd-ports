PORTNAME=	0d1n
PORTVERSION=	3.8
CATEGORIES=	security

MAINTAINER=	zackj901@yandex.com
COMMENT=	Open source web HTTP fuzzing tool and bruteforcer
WWW=		https://github.com/CoolerVoid/0d1n

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	CoolerVoid
GH_TAGNAME=	OdinV38

PLIST_FILES=	bin/0d1n
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD}  -e  '/^#include <alloca\.h>/d' \
	${WRKSRC}/src/headers/spider.h ${WRKSRC}/src/headers/results.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} 	    ${STAGEDIR}${DATADIR}/view
	${MKDIR} 	    ${STAGEDIR}${DATADIR}/view/response_sources
	${MKDIR} 	    ${STAGEDIR}${DATADIR}/payloads
	(cd ${WRKSRC} && ${COPYTREE_SHARE} templates  ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} payloads   ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
