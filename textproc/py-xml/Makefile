# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		xml
PORTVERSION=		0.7
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyxml
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		wjv@FreeBSD.org

BUILD_DEPENDS=		${PYDISTUTILS}

INSTALLS_SHLIB=		yes
# On a system with more than one version of Python installed, you can force
# this port to install for a specific version of Python by explicitly setting
# ${PYTHON_VERSION} during build/installation.
USE_PYTHON=		yes

.include <bsd.port.pre.mk>

CPIO=			cpio --quiet -pdum -R
DOCSDIR=		${PREFIX}/share/doc/py-xml
EXAMPLESDIR=		${PREFIX}/share/examples/py-xml
.if ${PYTHON_REL} < 200
PLIST_SUB+=		PACKAGE_DIR=xml
.else
PLIST_SUB+=		PACKAGE_DIR=_xmlplus
.endif

do-build:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py build

do-install:
	@ cd ${WRKSRC} && ${PYTHON_CMD} setup.py install -c -O1 \
	  --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ANNOUNCE CREDITS LICENCE README* TODO
	@ ${INSTALL_MAN} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ cd ${WRKSRC}/doc && find * \
	  | ${CPIO} ${MANOWN}:${MANGRP} ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ cd ${WRKSRC} && find demo test \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
