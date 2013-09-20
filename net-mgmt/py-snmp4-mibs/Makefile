# Created by: Martin Jackson <mhjacks@swbell.net>
# $FreeBSD$

PORTNAME=	snmp4-mibs
PORTVERSION=	0.1.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP \
		SF/pysnmp/pysnmp-mibs/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysnmp-mibs-${PORTVERSION}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	Additional python MIB files for pysnmp4 and friends

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snmp4>=4.2.3:${PORTSDIR}/net-mgmt/py-snmp4

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	pysnmp-mibs

PLIST_FILES+=	bin/rebuild-pysnmp-mibs \
		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	CHANGES \
		README

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
