# New ports collection makefile for:	py-zsi
# Date created:		17 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ZSI
DISTVERSION=	2.0-rc2
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywebsvcs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A pure Python module that provides an implementation of SOAP 1.1

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML}

NO_LATEST_LINK=	yes
CONFLICTS=	py-zsi-1.*

USE_PYTHON=	2.0+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
.for f in CHANGES README doc/zsi.* doc/*.tex
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.for subdir in interop samples test
	@${MKDIR} ${EXAMPLESDIR}/${subdir}
	@${CP} -rp ${WRKSRC}/${subdir}/* ${EXAMPLESDIR}/${subdir}
.endfor

.include <bsd.port.mk>
