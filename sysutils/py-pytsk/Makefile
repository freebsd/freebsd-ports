# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pytsk
DISTVERSION=	2012-11-10
PORTREVISION=	1
CATEGORIES=	sysutils security devel python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for the Sleuthkit

LICENSE=	AL2

LIB_DEPENDS=	tsk:${PORTSDIR}/sysutils/sleuthkit

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PYTHON=	-2.7
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=pytsk3
PYDISTUTILS_PKGVERSION=0.1

post-patch:
	${REINPLACE_CMD} -e '/socket\.h/ { h; s|socket|types|; G; }' ${WRKSRC}/misc.h
	${REINPLACE_CMD} -e 's|/usr/include/tsk3/|${LOCALBASE}/include/tsk/|' \
		-e "s|LIBRARY_DIRS = \[\]|LIBRARY_DIRS = ['${LOCALBASE}/lib/']|" \
		-e "s|LIBRARIES = \['tsk3'|LIBRARIES = ['tsk'|" \
		-e "s|= \[CONFIG\['TSK3_HEADER_LOCATION'\]\]|= ['${LOCALBASE}/include/']|" \
		${WRKSRC}/setup.py
	${REINPLACE_CMD} 's|tsk3/libtsk|tsk/libtsk|' ${WRKSRC}/tsk3.h

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	LICENSE README

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
PORTEXAMPLES=	*

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pytsk3.so

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
