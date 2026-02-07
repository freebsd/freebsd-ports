PORTNAME=	0d1n
DISTVERSION=	3.8
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	zackj901@yandex.com
COMMENT=	Open source web HTTP fuzzing tool and bruteforcer
WWW=		https://github.com/CoolerVoid/0d1n

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	CoolerVoid
GH_TAGNAME=	OdinV38

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's,/opt/0d1n,${DATADIR},g' \
		${WRKSRC}/src/headers/file_ops.h \
		${WRKSRC}/src/file_ops.c \
		${WRKSRC}/src/opt_extract.c \
		${WRKSRC}/src/results.c

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
