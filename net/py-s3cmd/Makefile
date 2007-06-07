# New ports collection makefile for:	s3cmd
# Date created:		2007-05-02
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	s3cmd
PORTVERSION=	0.9.2
CATEGORIES=	net python
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	s3tools
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Unix-like tools to manipulate stored files from the command line

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree

USE_PYDISTUTILS=	yes
USE_PYTHON=	yes

MAN1=		s3cmd.1

post-patch:
	${REINPLACE_CMD} -e '/^os.system/d' -e 's,share/man/man1,man/man1,' \
		${WRKSRC}/setup.py
.ifndef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,share/doc/packages/s3cmd,share/doc/s3cmd,' \
		${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/share.doc.packages.s3cmd/d' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
