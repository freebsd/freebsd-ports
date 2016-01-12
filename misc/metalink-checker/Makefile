# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metalink
PORTVERSION=	1.3
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}s/Metalink%20Checker/2007
PKGNAMESUFFIX?=	-checker
DISTNAME=	checker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script to check metalink files and complete a basic download

LICENSE=	GPLv2+

USES=		dos2unix python
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}.py

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s|#!/usr/bin/env[[:space:]]python|#!${PYTHON_CMD}|" \
		${WRKSRC}/${PORTNAME}.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
