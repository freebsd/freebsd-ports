# New ports collection makefile for:	wmmemload
# Date created:				14 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmmemload
PORTVERSION=	0.1.6
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.markstaggs.net/wmmemload/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	An dockapp for windowmaker that displays the current mem/swap usage

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmmemload.1

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
