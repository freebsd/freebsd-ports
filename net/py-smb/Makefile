# ex:ts=8
# Ports collection makefile for:	pysmb
# Date created:				Jan 11, 2002
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	smb
PORTVERSION=	1.1.1
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/files/Projects/py${PORTNAME}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysmb-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

# It's actually python3 ready since 1.1.1, but there is package list problem
# that I'm not sure how to solve right now. So let it stay stricted to 2.x.
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py${PORTNAME}

DOCSDIR=	${PREFIX}/share/doc/py-smb

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _modules/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} api/ ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${DOCSDIR}/)
	@(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${DOCSDIR}/)
.endif

.include <bsd.port.mk>
