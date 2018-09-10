# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	lava
PORTVERSION=	1.0.1
CATEGORIES=	sysutils

MAINTAINER=	dch@skunkwerks.at
COMMENT=	Keeps your CouchDB views molten hot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq:textproc/jq \
		curl:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	iwantmyname

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${PORTNAME}.sh
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}.sh

.include <bsd.port.mk>
