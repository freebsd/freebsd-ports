PORTNAME=	vultr-cli
PORTVERSION=	2.14.2
PORTREVISION=	10
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	antranigv@freebsd.am
COMMENT=	Official command line tool for Vultr services
WWW=		https://github.com/vultr/vultr-cli

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	vultr
GH_TUPLE=	golang:sys:v0.6.0:sys

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
