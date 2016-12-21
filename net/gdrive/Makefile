# Created by: Dmitri Goutnik <dg@syrec.org>
# $FreeBSD$

PORTNAME=	gdrive
PORTVERSION=	2.1.0
CATEGORIES=	net

MAINTAINER=	dg@syrec.org
COMMENT=	Google Drive CLI Client

LICENSE=	MIT

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	prasmussen

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/gdrive
PORTDOCS=	README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
