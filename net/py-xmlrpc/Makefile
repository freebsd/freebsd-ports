# New ports collection makefile for:	py-xmlrpc
# Date created:				22 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc
PORTVERSION=	0.8.7
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	py-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S/^${LOCALBASE}\///g} \
		SHARE_SUBDIR=${SHARE_SUBDIR}
SHARE_SUBDIR=   ${PKGNAMEPREFIX}${PORTNAME}
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/${SHARE_SUBDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} doc/example/* ${PREFIX}/share/examples/${SHARE_SUBDIR}
.endif

.include <bsd.port.mk>
