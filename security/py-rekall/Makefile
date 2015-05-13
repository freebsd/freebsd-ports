# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall
PORTVERSION=	1.3.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Memory forensics analysis framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	cabextract:${PORTSDIR}/archivers/cabextract \
		${PYTHON_PKGNAMEPREFIX}acora>=1.8:${PORTSDIR}/textproc/py-acora \
		${PYTHON_PKGNAMEPREFIX}PyAFF4>=0.12:${PORTSDIR}/security/py-pyaff4 \
		${PYTHON_PKGNAMEPREFIX}capstone>=0:${PORTSDIR}/devel/py-capstone \
		${PYTHON_PKGNAMEPREFIX}codegen>=1.0:${PORTSDIR}/devel/py-codegen \
		${PYTHON_PKGNAMEPREFIX}distorm>=0:${PORTSDIR}/devel/py-distorm \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Flask-Sockets>=0:${PORTSDIR}/www/py-flask-sockets \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.0.1:${PORTSDIR}/devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}gevent-websocket>=0.9.3:${PORTSDIR}/www/py-gevent-websocket \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.0.4:${PORTSDIR}/devel/py-intervaltree \
		${PYTHON_PKGNAMEPREFIX}ipython>=2.0.0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.3.1:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0.22:${PORTSDIR}/devel/py-pyelftools \
		${PYTHON_PKGNAMEPREFIX}pytz>=2012:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}yaml>=2.10:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}yara>=0:${PORTSDIR}/security/py-yara

USES=		python:2
USE_PYTHON=	distutils autoplist

PORTDOCS=	CREDITS.txt LEGAL.txt README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CHMOD} -R a+rX ${WRKSRC}
	@${REINPLACE_CMD} '/argparse/d ; /ipython/s/3.0.0/2.0.0/' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
