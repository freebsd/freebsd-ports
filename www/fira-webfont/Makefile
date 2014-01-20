# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	1.0
CATEGORIES=	www
PKGNAMESUFFIX=	-webfont

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced Web Font for small screens

LICENSE=	OFL
LICENSE_NAME=	SIL OPEN FONT LICENSE Version 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_PROJECT=	Fira
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	705ffff

NO_BUILD=	yes

PORTDOCS=	README.md
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message
PLIST_SUB=	WWWDIR_REL=${WWWDIR_REL}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/fira.css ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/eot
	${INSTALL_DATA} ${WRKSRC}/eot/${GH_PROJECT}*.eot ${STAGEDIR}${WWWDIR}/eot/
	@${MKDIR} ${STAGEDIR}${WWWDIR}/ttf
	${INSTALL_DATA} ${WRKSRC}/ttf/${GH_PROJECT}*.ttf ${STAGEDIR}${WWWDIR}/ttf/
	@${MKDIR} ${STAGEDIR}${WWWDIR}/woff
	${INSTALL_DATA} ${WRKSRC}/woff/${GH_PROJECT}*.woff ${STAGEDIR}${WWWDIR}/woff/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
