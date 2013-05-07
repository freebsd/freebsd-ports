# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
DISTVERSION=	1.0.1alpha
CATEGORIES=	security python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:${PORTSDIR}/devel/hachoir-core \
		${PYTHON_SITELIBDIR}/hachoir_metadata/__init__.py:${PORTSDIR}/sysutils/hachoir-metadata \
		${PYTHON_SITELIBDIR}/hachoir_parser/__init__.py:${PORTSDIR}/devel/hachoir-parser \
		${PYTHON_SITELIBDIR}/pyevt.so:${PORTSDIR}/devel/libevt \
		${PYTHON_SITELIBDIR}/pyevtx.so:${PORTSDIR}/devel/libevtx \
		${PYTHON_SITELIBDIR}/pylnk.so:${PORTSDIR}/devel/liblnk \
		${PYTHON_SITELIBDIR}/pymsiecf.so:${PORTSDIR}/devel/libmsiecf \
		${PYTHON_SITELIBDIR}/pyregf.so:${PORTSDIR}/devel/libregf \
		${PYTHON_SITELIBDIR}/pyvshadow.so:${PORTSDIR}/devel/libvshadow \
		ipython${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	2.7
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGVERSION=0.1
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

PORTDOCS=	AUTHORS
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTEXAMPLES=	README.tools image_export.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/tools/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
