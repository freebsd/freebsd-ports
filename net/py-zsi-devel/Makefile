# New ports collection makefile for:	py-zsi
# Date created:		17 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zsi
PORTVERSION=	1.22.6
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pywebsvcs
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION:C|\.([^.]*)$|-\1|}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-1.2

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.tex
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for subdir in interop samples test
	@ ${MKDIR} ${EXAMPLESDIR}/${subdir}
	@ ${INSTALL_DATA} ${WRKSRC}/${subdir}/* ${EXAMPLESDIR}/${subdir}
.endfor
.endif

.include <bsd.port.mk>
