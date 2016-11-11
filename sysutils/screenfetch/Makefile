# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	screenFetch
PORTVERSION=	3.7.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/jgh/sysutils/${PORTNAME:tl}/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Bash Screenshot Information Tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash \
		xdpyinfo:x11/xdpyinfo

OPTIONS_DEFINE=	DOCS

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
