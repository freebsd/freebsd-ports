# New ports collection makefile for:	py-slimmer
# Date created:		22 May 2006
# Whom:			Corey Smith
#
# $FreeBSD$
#

PORTNAME=	slimmer
PORTVERSION=	0.1.21
CATEGORIES=	www python
MASTER_SITES=	http://www.issuetrackerproduct.com/Download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	corsmith@gmail.com
COMMENT=	A whitespace optimizer for CSS, HTML and XHTML output

WRKSRC=		${WRKDIR}/slimmer

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGVERSION=	0.1.19

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/slimmer.py \
		%%PYTHON_SITELIBDIR%%/slimmer.pyc \
		%%PYTHON_SITELIBDIR%%/slimmer.pyo

.include <bsd.port.mk>
