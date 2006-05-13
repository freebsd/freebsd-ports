# New ports collection makefile for:	py-ltxml
# Date created:		31 January 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltxml
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyLTXML-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings to the LT XML toolkit

BUILD_DEPENDS=	${LOCALBASE}/include/ltxml12/lt-safe.h:${PORTSDIR}/textproc/ltxml
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
INSTALLS_SHLIB=	yes
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/group/ltg/projects/lcontrib9|${LOCALBASE}|' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/00README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/example/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
