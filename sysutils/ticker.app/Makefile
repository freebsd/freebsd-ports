# New ports collection makefile for:	ticker.app
# Date created:				Sun Oct 14 15:14:24 EDT 2001
# Whom:                                 Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	ticker.app
PORTVERSION=	0.5.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Ticker dockapp for Window Maker

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		ticker.app.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/ChangeLog \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
