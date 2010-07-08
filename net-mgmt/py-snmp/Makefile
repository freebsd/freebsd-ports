# New ports collection makefile for:	py-snmp
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	3.4.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}-devel/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP framework for Python

CONFLICTS=	py??-snmp2-[0-9]* py??-snmp4-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysnmp
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
