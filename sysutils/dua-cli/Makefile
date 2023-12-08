PORTNAME=	dua-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.20.1
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Conveniently learn about the disk usage of directories
WWW=		https://github.com/Byron/dua-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Byron

PLIST_FILES=	bin/dua
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dua

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
