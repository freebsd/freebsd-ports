# New ports collection makefile for:	py-posix1e
# Date created:		2 January 2003
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	posix1e
PORTVERSION=	0.5.0
CATEGORIES=	security python
MASTER_SITES=	SF/pylibacl/pylibacl/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylibacl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for manipulating POSIX.1e ACLs

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	pylibacl
PYEASYINSTALL_ARCHDEP=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

PORTDOCS=	COPYING IMPLEMENTATION NEWS PLATFORMS README
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
