# New ports collection makefile for:	wmcpuload
# Date created:				18 Apr 2001
# Whom:					Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	wmcpuload
PORTVERSION=	0.8.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/
DISTNAME=	WMCPULoad-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes

MAN1=		wmcpuload.1

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
