# ex:ts=8
# Ports collection makefile for:	linkchecker
# Date created:			Oct 17, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	linkchecker
PORTVERSION=	3.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Check HTML documents for broken links

USE_PYTHON=		2.4
USE_PYDISTUTILS=	yes
USE_REINPLACE=		yes
MAN1=	linkchecker.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's/gnu99/gnu89/' ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
