# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plaso
PORTVERSION=	1.0.2
CATEGORIES=	security python
MASTER_SITES=	https://googledrive.com/host/0B30H7z4S52FleW5vUHBnblJfcjg/${PORTVERSION}/final/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_source_${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Automatic creation of a super timeline

LICENSE=	APACHE20

RUN_DEPENDS=	hachoir-core>=0:${PORTSDIR}/devel/hachoir-core \
		hachoir-metadata>=0:${PORTSDIR}/sysutils/hachoir-metadata \
		hachoir-parser>=0:${PORTSDIR}/devel/hachoir-parser \
		libevt>=a:${PORTSDIR}/devel/libevt \
		libevtx>=a:${PORTSDIR}/devel/libevtx \
		liblnk>=0:${PORTSDIR}/devel/liblnk \
		libmsiecf>=a:${PORTSDIR}/devel/libmsiecf \
		libolecf>=a:${PORTSDIR}/devel/libolecf \
		libregf>=a:${PORTSDIR}/devel/libregf \
		libvshadow>=0:${PORTSDIR}/devel/libvshadow \
		${PYTHON_PKGNAMEPREFIX}binplist>=0:${PORTSDIR}/devel/py-binplist \
		${PYTHON_PKGNAMEPREFIX}construct>=0:${PORTSDIR}/devel/py-construct \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}docopt>=0:${PORTSDIR}/devel/py-docopt \
		${PYTHON_PKGNAMEPREFIX}dpkt>=0:${PORTSDIR}/net/py-dpkt \
		${PYTHON_PKGNAMEPREFIX}ipython>=0:${PORTSDIR}/devel/ipython \
		${PYTHON_PKGNAMEPREFIX}parsing>=0:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}protobuf>=0:${PORTSDIR}/devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pytsk>=0:${PORTSDIR}/sysutils/py-pytsk \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGVERSION=${PORTVERSION}alpha
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	ACKNOWLEDGEMENT AUTHORS
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
