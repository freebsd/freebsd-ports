PORTNAME=	lsix
PORTVERSION=	1.8.2
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	List files with thumbnails using Sixel graphics
WWW=		https://github.com/hackerb9/lsix

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash

FLAVORS=	x11 nox11
USES=		magick:${FLAVOR},run
USE_GITHUB=	yes
GH_ACCOUNT=	hackerb9

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

nox11_PKGNAMESUFFIX=	-nox11
nox11_CONFLICTS_INSTALL=${PORTNAME}
x11_CONFLICTS_INSTALL=	${PORTNAME}${nox11_PKGNAMESUFFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${WRKSRC}/README.md* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
