# Created by: Martin Jackson <mhjacks@swbell.net>
# $FreeBSD$

PORTNAME=	snmp4-apps
PORTVERSION=	0.3.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP \
		SF/pysnmp/pysnmp-apps/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-apps-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Command line utilities for pysnmp4

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snmp4>=4.2.3:${PORTSDIR}/net-mgmt/py-snmp4

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	CHANGES README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
