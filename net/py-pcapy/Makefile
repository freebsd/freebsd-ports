# New ports collection makefile for:	pcapy
# Date created:				15th September 2005
# Whom:					Marcin Jessa <yazzy@yazzy.org>
# $FreeBSD$

PORTNAME=	pcapy
PORTVERSION=	0.10.5
CATEGORIES=	net python
MASTER_SITES=	http://oss.coresecurity.com/repo/ \
		http://www.yazzy.org/ports/pcapy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python extension module to capture packets on the network

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pcapy.so
PORTDOCS=	README LICENSE pcapy.html

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
