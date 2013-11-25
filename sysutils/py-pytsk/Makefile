# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytsk
DISTVERSION=	2013-11-24
CATEGORIES=	sysutils security devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	AL2

LIB_DEPENDS=	libtsk.so:${PORTSDIR}/sysutils/sleuthkit

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
python_CMD=	${PYTHON_CMD}
USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=pytsk3
PYDISTUTILS_PKGVERSION=4.1.2

post-patch:
	${REINPLACE_CMD} -e "s|'/', 'usr', 'local'|'${LOCALBASE}'|" \
		${WRKSRC}/setup.py

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	README

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pytsk3.so

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.py ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
