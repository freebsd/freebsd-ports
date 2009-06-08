#
# Ports collection makefile for:	py-lucene
# Date created:				Nov 2, 2006
# Whom:					Frank J. Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	PyLucene
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	textproc devel python java
MASTER_SITES=	http://downloads.osafoundation.org/PyLucene/jcc/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}${PATCHSET}-src-jcc

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A GCJ-compiled version of Java Lucene integrated with Python

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		${PYTHON_PKGNAMEPREFIX}jcc>0:${PORTSDIR}/devel/py-jcc \
		${NONEXISTENT}:${PORTSDIR}/textproc/lucene:extract

USE_PYTHON=	2.4+
USE_GCC=	4.2+
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_GMAKE=	yes
PATCHSET=	-1
LUCENE_VER=	2.4.1
#EGG_INFO=	lucene-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info
EGG_INFO=	lucene-${LUCENE_VER}-${PYTHON_VERSION:S/thon//}.egg-info

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}${PATCHSET}
PLIST_SUB=	EGG_INFO=${EGG_INFO}

MAKE_ENV+=	LD_LIBRARY_PATH="${JAVA_HOME}/jre/lib/${ARCH}:${JAVA_HOME}/jre/lib/${ARCH}/server"
MAKE_ARGS+=	PREFIX=${PREFIX} PREFIX_PYTHON=${LOCALBASE} PYTHON=${PYTHON_CMD} \
		LDFLAGS+=-L${LOCALBASE}/lib PYTHON_INC=${PYTHON_INCLUDEDIR} \
		PYTHON_SITE=${PYTHON_SITELIBDIR}

pre-build:
		${CP} -R ${WRKDIR}/../../lucene/work/lucene-${LUCENE_VER} ${WRKSRC}/lucene-java-${LUCENE_VER}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 250
BROKEN=		Doesn't build with ${PYTHON_VERSION}
.endif

#regression-test:
#		cd ${WRKSRC}; env ${MAKE_ENV} ${GMAKE} test

.include <bsd.port.post.mk>
