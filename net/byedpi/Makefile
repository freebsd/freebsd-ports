PORTNAME=	byedpi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.3
CATEGORIES=	net

MAINTAINER=	makc@FreeBSD.org
COMMENT=	SOCKS proxy server to bypass DPI
WWW=		https://github.com/hufrea/byedpi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	hufrea

USE_RC_SUBR=	byedpi

PLIST_FILES=	bin/ciadpi
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ciadpi

.include <bsd.port.mk>
