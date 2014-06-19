# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	hatop
PORTVERSION=	0.7.7
CATEGORIES=	sysutils net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@christianserving.org
COMMENT=	An interactive real-time monitoring tool for the HAProxy unix socket

RUN_DEPENDS=	${LOCALBASE}/sbin/haproxy:${PORTSDIR}/net/haproxy

USE_PYTHON=	yes
NO_BUILD=	yes

LICENSE=	GPLv3

PLIST_FILES=	bin/hatop man/man1/hatop.1.gz
PORTDOCS=	HACKING KEYBINDS README

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop ${STAGEDIR}${PREFIX}/bin/hatop
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
