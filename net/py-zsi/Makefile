# New ports collection makefile for:	py-zsi
# Date created:		17 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zsi
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pywebsvcs/ZSI/ZSI-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A pure Python module that provides an implementation of SOAP 1.1

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML}

CONFLICTS=	py-zsi-devel-2.*

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	ZSI

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.tex
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
.for subdir in interop samples test
	@${MKDIR} ${EXAMPLESDIR}/${subdir}
	@${CP} -rp ${WRKSRC}/${subdir}/* ${EXAMPLESDIR}/${subdir}
.endfor
.endif

.include <bsd.port.mk>
