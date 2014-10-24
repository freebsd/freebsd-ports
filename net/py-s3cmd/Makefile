# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	s3cmd
DISTVERSION=	1.5.0-rc1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	SF/s3tools/${PORTNAME}/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Unix-like tools to manipulate stored files from the command line

USES=		python:2
USE_PYTHON=	distutils autoplist

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/setup.py
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's,doc/packages,doc,' ${WRKSRC}/setup.py
.else
	${REINPLACE_CMD} -e '/(doc_path+/d' ${WRKSRC}/setup.py
.endif

.include <bsd.port.mk>
