# New ports collection makefile for:	py-snmp
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	2.0.3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
USE_REINPLACE=	yes
USE_PYDISTUTILS=yes
EXAMPLESDIR=	${PREFIX}/share/examples/py-snmp
DOCSDIR=	${PREFIX}/share/doc/py-snmp

post-patch:
	@${REINPLACE_CMD} -E -e 's|^(#!/usr/bin/env[ ]+)python|\1${PYTHON_CMD}|' \
		${WRKSRC}/setup.py

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
