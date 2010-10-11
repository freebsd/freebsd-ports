# New ports collection makefile for:	hatop
# Date created:		2010-08-16
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

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

PLIST_FILES=	bin/hatop
PORTDOCS=	HACKING KEYBINDS README

MAN1=		hatop.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop ${PREFIX}/bin/hatop
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR})
.endif

.include <bsd.port.mk>
