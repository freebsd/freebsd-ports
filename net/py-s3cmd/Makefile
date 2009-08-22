# New ports collection makefile for:	s3cmd
# Date created:		2007-05-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	s3cmd
PORTVERSION=	0.9.9
CATEGORIES=	net python
MASTER_SITES=	SF/s3tools/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Unix-like tools to manipulate stored files from the command line

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

MAN1=		s3cmd.1

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/setup.py
.ifndef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,doc/packages,doc,' ${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/(doc_path+/d' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
