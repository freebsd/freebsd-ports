# New ports collection makefile for:	wmlongrun
# Date created:				Sat Mar 23 21:00:03 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmlongrun
PORTVERSION=	0.2.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A dockapp to monitor the LongRun(tm) status on Crusoe

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmlongrun.1

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
