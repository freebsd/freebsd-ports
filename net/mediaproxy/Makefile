# New ports collection makefile for:	mediaproxy
# Date created:				08 August 2006
# Whom:					Steve Ames <steve@energistic.com>
#
# $FreeBSD$

PORTNAME=	mediaproxy
PORTVERSION=	1.8.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://mediaproxy.ag-projects.com/ \
		http://mediaproxy.ag-projects.com/old/

MAINTAINER=	steve@energistic.com
COMMENT=	A far-end NAT traversal solution for SER/OpenSER

USE_RC_SUBR=	mediaproxy.sh

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	2.5+

OPTIONS=	ACCOUNTING "ACCOUNTING support (Requires MySQL)" off

.include <bsd.port.pre.mk>

.if defined(WITH_ACCOUNTING)
USE_MYSQL=	yes
.endif

post-install:
	${CP} -pRP ${WRKSRC}/ ${PREFIX}/mediaproxy
	${CHOWN} -R 0:0 ${PREFIX}/mediaproxy

.include <bsd.port.post.mk>
