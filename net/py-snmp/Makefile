# New ports collection makefile for:	py-snmp
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	3.1.3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
EXAMPLESDIR=	${PREFIX}/share/examples/py-snmp
DOCSDIR=	${PREFIX}/share/doc/py-snmp

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | ${TAR} -C ${DOCSDIR} -xf -
.endif

.include <bsd.port.mk>
