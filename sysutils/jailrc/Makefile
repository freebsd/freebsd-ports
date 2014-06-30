# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jailrc
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	#
DISTFILES=	#

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Improved jail startup/shutdown script

NO_BUILD=	yes
NO_INSTALL=	yes
USE_RC_SUBR=	jailrc
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${DOCSDIR}/README
.endif

.include <bsd.port.mk>
