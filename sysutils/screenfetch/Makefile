PORTNAME=	screenFetch
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.9
CATEGORIES=	sysutils

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Bash Screenshot Information Tool
WWW=		https://github.com/KittyKatt/screenFetch

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=		bash:shells/bash
default_RUN_DEPENDS=	xdpyinfo:x11/xdpyinfo

FLAVORS=		default nox11
FLAVOR?=		${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

CONFLICTS_INSTALL=	screenFetch-nox11*

OPTIONS_DEFINE=	DOCS

NO_BUILD=	yes
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	KittyKatt

PLIST_FILES=	bin/screenFetch \
		bin/screenfetch \
		share/man/man1/screenfetch.1.gz
PORTDOCS=	CHANGELOG README.mkdn TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME:tl}-dev ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${LN} -fs ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/screenfetch
	${INSTALL_MAN} ${WRKSRC}/screenfetch.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	cd ${WRKSRC} && ./${PORTNAME:tl}-dev

.include <bsd.port.mk>
