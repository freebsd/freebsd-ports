# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		xml
PORTVERSION=		0.6.4
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}                     \
			http://www.python.org/sigs/xml-sig/files/      \
			ftp://ftp.cdrom.com/pub/python/www.python.org/sigs/xml-sig/files/ \
			ftp://unix.hensa.ac.uk/mirrors/ftp.python.org/pub/www.python.org/sigs/xml-sig/files/
MASTER_SITE_SUBDIR=	pyxml
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		johann@egenetics.com

BUILD_DEPENDS=		${PYDISTUTILS}

USE_PYTHON=		yes

.include <bsd.port.pre.mk>

CPIO=			cpio --quiet -pdum -R
DOCDIR=			${PREFIX}/share/doc/py-xml
.if ${PYTHON_VERSION} == "python1.5"
PLIST_SUB+=		PACKAGE_DIR=xml
.else
PLIST_SUB+=		PACKAGE_DIR=_xmlplus
.endif

do-build:
	@ (cd ${WRKSRC} && ${PYTHON_CMD} setup.py build)

do-install:
	@ (cd ${WRKSRC} && ${PYTHON_CMD} setup.py install)

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCDIR}
	@ (cd ${WRKSRC}/doc && find . \
	  | ${CPIO} ${MANOWN}:${MANGRP} ${DOCDIR})
.endif

.include <bsd.port.post.mk>
