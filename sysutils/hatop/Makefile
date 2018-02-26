# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	hatop
PORTVERSION=	0.7.7
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils net

MAINTAINER=	ports@christianserving.org
COMMENT=	Interactive real-time monitoring tool for the HAProxy unix socket

LICENSE=	GPLv3+

RUN_DEPENDS=	${LOCALBASE}/sbin/haproxy:net/haproxy

USES=		python:2.7 shebangfix
SHEBANG_FILES=	bin/hatop
NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	feurix
GH_PROJECT=	hatop

PLIST_FILES=	bin/hatop man/man1/hatop.1.gz
PORTDOCS=	HACKING KEYBINDS README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop ${STAGEDIR}${PREFIX}/bin/hatop
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
