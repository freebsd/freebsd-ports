# Ports collection Makefile for:	PyXML
# Date created:				04/17/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		xml
PORTVERSION=		0.8
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyxml
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		PyXML-${PORTVERSION}

MAINTAINER=		wjv@FreeBSD.org

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

CPIO=			cpio --quiet -pdum -R
DOCSDIR=		${PREFIX}/share/doc/py-xml
EXAMPLESDIR=		${PREFIX}/share/examples/py-xml
.if ${PYTHON_REL} < 200
PLIST_SUB+=		PACKAGE_DIR=xml
.else
PLIST_SUB+=		PACKAGE_DIR=_xmlplus
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ANNOUNCE CREDITS LICENCE README* TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ cd ${WRKSRC}/doc && find * \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ cd ${WRKSRC} && find demo test \
	  | ${CPIO} ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
