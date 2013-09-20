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

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${FILESDIR}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
