# New ports collection makefile for:	qtfw
# Date created:				Sat Aug 25 10:42:02 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	qtfw
PORTVERSION=	0.3.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@databits.net

ALL_TARGET=	${PORTNAME}
USE_QT_VER=	2

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/examples/* \
		${PREFIX}/share/examples/${PORTNAME}
.endif

.include <bsd.port.mk>
