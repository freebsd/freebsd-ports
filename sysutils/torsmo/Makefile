# New ports collection makefile for:	torsmo
# Date created:		2004-07-29
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	torsmo
PORTVERSION=	0.17
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	bogorodskiy@inbox.ru
COMMENT=	System monitor that renders text on desktop

USE_AUTOCONF_VER=259
USE_AUTOMAKE_VER=14
USE_X_PREFIX=	yes
MAN1=	torsmo.1

PLIST_FILES=	bin/torsmo \
		%%EXAMPLESDIR%%/torsmorc.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/freebsd.c ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/torsmorc.sample ${EXAMPLESDIR}

.include <bsd.port.post.mk>
