PORTNAME=	so
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.6
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Terminal interface for Stack Overflow

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	samtay

PLIST_FILES=	bin/so
PORTDOCS=	*.md
PORTDATA=	themes/*.toml

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/so
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} themes ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/bsd.so.mk"
.include <bsd.port.mk>
