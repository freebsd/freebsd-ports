# New ports collection makefile for:	py-zsi
# Date created:		17 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zsi
PORTVERSION=	1.7
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywebsvcs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure Python module that provides an implementation of SOAP 1.1

USE_PYTHON=	2.0+
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.tex
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for subdir in interop samples test
	@ ${MKDIR} ${EXAMPLESDIR}/${subdir}
	@ ${CP} -rp ${WRKSRC}/${subdir}/* ${EXAMPLESDIR}/${subdir}
.endfor
.endif

.include <bsd.port.mk>
