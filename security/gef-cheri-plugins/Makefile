PORTNAME=	gef-cheri-plugins
DISTVERSION=	${GEF_PLUGINS_VERSION}
PORTREVISION=	0
CATEGORIES=	security python

MAINTAINER=	zyj20@cl.cam.ac.uk
COMMENT=	Extra plugins for GDB GEF
WWW=		https://github.com/CTSRD-CHERI/gef-plugins

LICENSE=	BSD2CLAUSE
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/gef-cheri/gef.py:security/gef-cheri

USES=		python:run

USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	gef-plugins
GH_TAGNAME=	${GEF_PLUGINS_COMMIT}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	${DATADIR_REL}/jemalloc_ext.py \
		${DATADIR_REL}/snmalloc_ext.py

post-patch:
	${REINPLACE_CMD} 's|%%PYTHON%%|${PYTHON_CMD:T}|g' ${WRKSRC}/*.py

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jemalloc_ext.py ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/snmalloc_ext.py ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/Makefile.snapshot"
.include <bsd.port.mk>
