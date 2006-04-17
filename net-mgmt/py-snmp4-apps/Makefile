# New ports collection makefile for:	py-pysnmp4-apps
# Date created:				Sun Apr  9 23:07:14 CDT 2006
# Whom:			Martin Jackson <mhjacks@swbell.net>
#
# $FreeBSD$
#

PORTNAME=	snmp4-apps
PORTVERSION=	0.2.3a
CATEGORIES=	net-mgmt python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pysnmp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-apps-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Command line utilities for pysnmp4

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysnmp/v4/__init__.py:${PORTSDIR}/net-mgmt/py-snmp4

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES \
		LICENSE \
		README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
