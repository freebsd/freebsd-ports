# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	1.1.0
CATEGORIES=	security python
MASTER_SITES=	https://googledrive.com/host/0B30H7z4S52FleW5vUHBnblJfcjg/${PORTVERSION}/release/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20

RUN_DEPENDS=	hachoir-core>=0:${PORTSDIR}/devel/hachoir-core \
		hachoir-metadata>=0:${PORTSDIR}/sysutils/hachoir-metadata \
		hachoir-parser>=0:${PORTSDIR}/devel/hachoir-parser \
		libesedb>=e:${PORTSDIR}/devel/libesedb \
		libevt>=a:${PORTSDIR}/devel/libevt \
		libevtx>=a:${PORTSDIR}/devel/libevtx \
		liblnk>=0:${PORTSDIR}/devel/liblnk \
		libmsiecf>=a:${PORTSDIR}/devel/libmsiecf \
		libolecf>=a:${PORTSDIR}/devel/libolecf \
		libregf>=a:${PORTSDIR}/devel/libregf \
		${PYTHON_PKGNAMEPREFIX}bencode>=0:${PORTSDIR}/converters/py-bencode \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:${PORTSDIR}/devel/py-binplist \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}dfvfs>=0:${PORTSDIR}/security/py-dfvfs \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:${PORTSDIR}/net/py-dpkt \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}parsing>=0:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}psutil121>=0:${PORTSDIR}/sysutils/py-psutil121 \
		${PYTHON_PKGNAMEPREFIX}pyelasticsearch>=0:${PORTSDIR}/textproc/py-pyelasticsearch \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml

USES=		python:2
USE_PYTHON=	distutils autoplist

PORTDOCS=	ACKNOWLEDGEMENTS AUTHORS
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
