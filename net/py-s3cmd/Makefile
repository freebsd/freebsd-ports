# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3cmd
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	SF/s3tools/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Unix-like tools to manipulate stored files from the command line

USE_PYDISTUTILS=	yes
USE_PYTHON=	2

MAN1=		s3cmd.1

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/setup.py
.ifndef(NOPORTDOCS)
	${REINPLACE_CMD} -e 's,doc/packages,doc,' ${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/(doc_path+/d' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
