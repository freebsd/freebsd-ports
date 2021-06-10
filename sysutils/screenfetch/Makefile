# Created by: Jason Helfman <jgh@FreeBSD.org>

PORTNAME=	screenFetch
DISTVERSIONPREFIX=	v
DISTVERSION=	3.9.1-56
DISTVERSIONSUFFIX=	-gc3a4789
CATEGORIES=	sysutils

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Bash Screenshot Information Tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash
X11_RUN_DEPENDS=	xdpyinfo:x11/xdpyinfo

CONFLICTS_INSTALL?=	screenFetch-nox11

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11

NO_BUILD=	yes
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	KittyKatt

PLIST_FILES=	bin/screenFetch bin/screenfetch man/man1/screenfetch.1.gz
PORTDOCS=	CHANGELOG README.mkdn TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME:tl}-dev ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${LN} -fs ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/screenfetch
	${INSTALL_MAN} ${WRKSRC}/screenfetch.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	cd ${WRKSRC} && ./${PORTNAME:tl}-dev

.include <bsd.port.mk>
