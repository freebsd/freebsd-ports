# New ports collection makefile for:	py-zsi
# Date created:		17 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	zsi
PORTVERSION=	1.1
CATEGORIES=	net python
MASTER_SITES=	http://www.zolera.com/resources/opensrc/zsi/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wjv@FreeBSD.org

RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME:U}-${PORTVERSION}

do-build:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py build

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py install -c -O1 --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.tex
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
