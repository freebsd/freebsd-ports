# New ports collection makefile for:	py-snmp
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	1.6.5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/py-snmp
DOCSDIR=	${PREFIX}/share/doc/py-snmp
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install -c -O1 --prefix=${PREFIX}

.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
