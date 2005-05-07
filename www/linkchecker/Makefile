# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Check HTML documents for broken links

USE_PYTHON=		2.4
USE_PYDISTUTILS=	yes

MAN1=	linkchecker.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.include <bsd.port.post.mk>
