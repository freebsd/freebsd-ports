# New ports collection makefile for:	Impacket
# Date created:				15th September 2005
# Whom:					Marcin Jessa <yazzy@yazzy.org>
#
# $FreeBSD$

PORTNAME=	Impacket
PORTVERSION=	0.9.5.1
CATEGORIES=	net python
MASTER_SITES=	http://oss.coresecurity.com/repo/ \
		http://www.yazzy.org/ports/impacket/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yazzy@yazzy.org
COMMENT=	Collection of Python classes providing access to network packets

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pcapy.so:${PORTSDIR}/net/py-pcapy

USE_PYTHON=	yes
NO_BUILD=	yes
USE_PYDISTUTILS=yes
PORTDOCS=	README	LICENSE

.if defined(NOPORTDOCS)
post-install:
	@${RM} ${DOCSDIR}/README
	@${RM} ${DOCSDIR}/LICENSE
	@${RMDIR} ${DOCSDIR}
	@${ECHO} "Removing ${DOCSDIR} and the files in it."
.endif

.include <bsd.port.mk>
