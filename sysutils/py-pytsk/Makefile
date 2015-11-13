# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytsk
PORTVERSION=	20150406
PORTREVISION=	1
CATEGORIES=	sysutils security devel python
MASTER_SITES=	https://github.com/py4n6/pytsk/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	APACHE20

LIB_DEPENDS=	libtsk.so:${PORTSDIR}/sysutils/sleuthkit

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		python shebangfix tar:tgz
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
USE_PYTHON=	distutils autoplist

PORTDOCS=	README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} 's|"/", "usr", "local"|"${LOCALBASE}"|' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
