# New ports collection makefile for:	py-pysnmp4
# Date created:		Sat Apr  8 21:51:59 CDT 2006
# Whom:			Martin Jackson <mhjacks@swbell.net>
#
# $FreeBSD$
#

PORTNAME=	snmp4
PORTVERSION=	4.1.10a
CATEGORIES=	net-mgmt python
MASTER_SITES=	SF/pysnmp/pysnmp-devel/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	SNMP framework for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pyasn1/__init__.py:${PORTSDIR}/devel/py-asn1 \
		${PYTHON_SITELIBDIR}/Crypto/__init__.py:${PORTSDIR}/security/py-pycrypto

CONFLICTS=	py??-snmp-[0-9]* py??-snmp2-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	pysnmp
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	*

BASEDOCS=	CHANGES \
		LICENSE \
		README \
		TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${BASEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${CP} -Rv ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for d in examples tools
	@${CP} -Rv ${WRKSRC}/${d}/* ${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
