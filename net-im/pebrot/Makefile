# New ports collection makefile for:	pebrot
# Date created:		26 March 2004
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	pebrot
PORTVERSION=	0.8.7.1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Text-based MSN messenger client

USE_PYTHON=	2.1+
USE_PYDISTUTILS=	yes

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d | ${XARGS} ${RM} -fr

.include <bsd.port.mk>
