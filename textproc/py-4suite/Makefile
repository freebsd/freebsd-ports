# New ports collection makefile for:	py-4suite
# Date created:		16 March 2000
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	4suite
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.4suite.org/pub/4Suite/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	4Suite-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML}

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_INSTALLARGS=	-c -O1 --prefix=${PREFIX} \
		--install-data=${PREFIX}/share

.include <bsd.port.pre.mk>
.if ${PYTHON_VERSION} == "python1.5" || ${PYTHON_VERSION} == "python1.6"
PLIST_SUB+=	PACKAGE_DIR=xml PYTHON2_ONLY="@comment "
.else
PLIST_SUB+=	PACKAGE_DIR=_xmlplus PYTHON2_ONLY=""
.endif

post-patch:
	@ ${REINPLACE_CMD} -e \
	  's#(copy_to=.)docs#$$1doc/${PORTNAME}#; \
	   s#(copy_to=.)(test_suite|demo)#$$1examples/${PORTNAME}/$$2#' \
	  ${WRKSRC}/setup.py
.if defined(NOPORTDOCS)
	@ ${REINPLACE_CMD} -e 's/(data_files=)data_files/$$1/' \
	  ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
