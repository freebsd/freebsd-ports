# New ports collection makefile for:   flowd
# Date created:        9 October 2004
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	softflowd
PORTVERSION=	0.9.7
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www2.mindrot.org/files/softflowd/

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Softflowd is flow-based network traffic analyser with export

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PLIST_FILES=	sbin/softflowd sbin/softflowctl
MAN8=		softflowd.8 softflowctl.8
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
