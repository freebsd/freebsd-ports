# New ports collection makefile for:	py-xmlrpc
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	0.8.8.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-xmlrpc

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf- . | ${TAR} -C ${EXAMPLESDIR} -xpf-
.endif

.include <bsd.port.mk>
