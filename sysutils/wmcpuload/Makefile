# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	1.0.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	pat@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes
CONFIGURE_ARGS=	--program-prefix=""

MAN1=		wmcpuload.1

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
