# New ports collection makefile for:		proxytunnel
# Date created:			Sun Nov 25 15:16:44 BRST 2001
# Whom:			Hammurabi Mendes <hmendes@brturbo.com>
#
# $FreeBSD$
#

PORTNAME=	proxytunnel
PORTVERSION=	1.2.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connects stdin and stdout to an origin server through an HTTPS proxy

ALL_TARGET=	${PORTNAME}
USE_GETOPT_LONG=yes

PLIST_FILES=	bin/proxytunnel
PORTDOCS=	CHANGES CREDITS README

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
