PORTNAME=	so
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.6
PORTREVISION=	29
CATEGORIES=	www

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Terminal interface for Stack Overflow
WWW=		https://github.com/samtay/so

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	samtay

PLIST_FILES=	bin/so
PORTDATA=	themes/*.toml
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} themes ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
