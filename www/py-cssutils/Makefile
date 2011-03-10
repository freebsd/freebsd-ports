# ex:ts=8
# Ports collection makefile for:	py-cssutils
# Date created:			Aug 26, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cssutils
PORTVERSION=	0.9.7
PORTEPOCH=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	CSS Cascading Style Sheets library for Python

USE_ZIP=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
