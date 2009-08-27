# New ports collection makefile for:	py-netaddr
# Date created:		2008-10-14
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	netaddr
PORTVERSION=	0.7.2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A python library for the manipulation of network address manipulation

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTDOCS=	AUTHORS CHANGELOG README
TESTFILES=	__init__.py

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

x-regression-test:
.for f in ${TESTFILES}
	(cd ${WRKSRC}/netaddr/tests && ${PYTHON_CMD} $f)
.endfor

.include <bsd.port.mk>
