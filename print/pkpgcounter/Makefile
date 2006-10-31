# Ports collection Makefile for:	pkpgcounter
# Date created:				Jan 1 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkpgcounter
PORTVERSION=	2.11
CATEGORIES=	print python
MASTER_SITES=	http://www.pykota.com/software/pkpgcounter/download/tarballs/

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A generic Page Description Language parser

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=		pkpgcounter.1
NOMANCOMPRES=	no

PORTDOCS=	README COPYING BUGS CREDITS NEWS

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_MAN} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.mk>
