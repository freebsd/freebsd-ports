# New ports collection makefile for:	wmmemmon
# Date created:				Wed May  9 17:55:21 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmmemmon
PORTVERSION=	0.7.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	pat@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmmemmon.1

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/ChangeLog \
		${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
