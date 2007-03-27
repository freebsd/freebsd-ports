# New ports collection makefile for:	py-webunit
# Date created:		Mar. 03, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	webunit
PORTVERSION=	1.3.9
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/w/webunit/ \
		http://mechanicalcat.net/tech/webunit/ \
		http://funkload.nuxeo.org/3dparty/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@lwhsu.org
COMMENT=	Unit test your websites with code that acts like a web browser

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EXAMPLESDIR=	${TARGETDIR}/share/examples/py-${PORTNAME}

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/run_tests ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/demo ${EXAMPLESDIR}

.include <bsd.port.mk>
