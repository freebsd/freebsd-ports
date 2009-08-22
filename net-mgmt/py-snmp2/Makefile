# New ports collection makefile for:	py-snmp2
# Date created:		16 Aug 2006
# Whom:			Dmitriy Kirhlarov
#
# $FreeBSD$
#

PORTNAME=	snmp2
PORTVERSION=	2.0.9
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/pysnmp/pysnmp/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	dimma@higis.ru
COMMENT=	SNMP framework for Python

CONFLICTS=	py??-snmp4-[0-9]* py??-snmp-3.*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysnmp
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
MYPORTDOCS=	CHANGES LICENSE MANIFEST PKG-INFO README contribution/WARNING

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/examples -cf - . | ${TAR} -C ${EXAMPLESDIR} -xf -
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/html -cf - . | ${TAR} -C ${DOCSDIR} -xf -
	${TAR} -C ${WRKSRC}/ -cf - ${MYPORTDOCS} | ${TAR} -C ${DOCSDIR} -xf -

.endif

.include <bsd.port.mk>
