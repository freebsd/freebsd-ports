# ex:ts=8
# Ports collection makefile for:	py-msnp
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	msnp
PORTVERSION=	0.4.0
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MSN messaging in Python

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutorial.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
