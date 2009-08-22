# New ports collection makefile for:	py-pysnmp4-mibs
# Date created:				Sun Apr  9 23:07:14 CDT 2006
# Whom:			Martin Jackson <mhjacks@swbell.net>
#
# $FreeBSD$
#

PORTNAME=	snmp4-mibs
PORTVERSION=	0.0.6a
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/pysnmp/pysnmp-mibs-devel/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-mibs-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Additional python MIB files for pysnmp4 and friends

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyasn1/__init__.py:${PORTSDIR}/devel/py-asn1

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysnmp-mibs

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES \
		LICENSE \
		README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
