# $FreeBSD$

PORTNAME=	0d1n
PORTVERSION=	2.3
CATEGORIES=	security

MAINTAINER=	zackj901@yandex.com
COMMENT=	Open source web HTTP fuzzing tool and bruteforcer

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	CoolerVoid

PLIST_FILES=	bin/0d1n
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^#include <alloca\.h>/d' \
		${WRKSRC}/get_csrf_token.h ${WRKSRC}/spider.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
