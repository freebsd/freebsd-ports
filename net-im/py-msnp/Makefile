# ex:ts=8
# Ports collection makefile for:	py-msnp
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	msnp
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.py-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MSN messaging in Python

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	msnp.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tutorial.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
