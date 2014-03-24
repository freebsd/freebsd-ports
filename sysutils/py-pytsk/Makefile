# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytsk
PORTVERSION=	20140320
CATEGORIES=	sysutils security devel python
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiScUxsUm54cG02RDA/ \
		LOCAL/antoine
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	APACHE20

LIB_DEPENDS=	libtsk.so:${PORTSDIR}/sysutils/sleuthkit

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix tar:tgz
SHEBANG_FILES=	samples/*.py
python_OLD_CMD=	.*
python_CMD=	${PYTHON_CMD}
USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	README
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} -e "s|'/', 'usr', 'local'|'${LOCALBASE}'|" \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/samples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
