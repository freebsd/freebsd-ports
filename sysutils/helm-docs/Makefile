PORTNAME=	helm-docs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.14.2
CATEGORIES=	sysutils

MAINTAINER=	owlandrews@protonmail.com
COMMENT=	Automatically generate markdown documentation from helm charts
WWW=		https://github.com/norwoodj/helm-docs

LICENSE=	GPLv3

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	norwoodj

GO_MOD_DIST=	github
GO_MODULE=	github.com/norwoodj/helm-docs
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
