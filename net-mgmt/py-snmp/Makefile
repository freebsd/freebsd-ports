# New ports collection makefile for:	py-snmp
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	3.4.3
CATEGORIES=	net-mgmt python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	SNMP framework for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
