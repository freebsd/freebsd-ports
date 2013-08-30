# Created by: Frank J. Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	PyLucene
PORTVERSION=	3.6.2
CATEGORIES=	textproc devel python java
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	lucene/pylucene
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylucene-${PORTVERSION}${PATCHSET}-src

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A GCJ-compiled version of Java Lucene integrated with Python

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		${PYTHON_PKGNAMEPREFIX}jcc>0:${PORTSDIR}/devel/py-jcc
FETCH_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/textproc/lucene:extract

BROKEN=		fails to build

USE_PYTHON=	2.5+
USE_GCC=	4.2+
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_GMAKE=	yes
PATCHSET=	-1
LUCENE_VER=	${PORTVERSION}
EGG_INFO=	lucene-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info
#EGG_INFO=	lucene-${LUCENE_VER}-${PYTHON_VERSION:S/thon//}.egg-info

WRKSRC=		${WRKDIR}/pylucene-${PORTVERSION}${PATCHSET}
PLIST_SUB=	EGG_INFO=${EGG_INFO}

MAKE_ENV+=	LD_LIBRARY_PATH="${JAVA_HOME}/jre/lib/${ARCH}:${JAVA_HOME}/jre/lib/${ARCH}/server"
MAKE_ARGS+=	PREFIX=${PREFIX} PREFIX_PYTHON=${LOCALBASE} PYTHON=${PYTHON_CMD} \
		LDFLAGS+=-L${LOCALBASE}/lib PYTHON_INC=${PYTHON_INCLUDEDIR} \
		PYTHON_SITE=${PYTHON_SITELIBDIR}

.include <bsd.port.pre.mk>

pre-build:
		${CP} -R ${WRKDIR}/../../lucene/work/lucene-${LUCENE_VER} ${WRKSRC}/lucene-java-${LUCENE_VER}
		@${REINPLACE_CMD} -e 's,-m jcc,-m jcc.__main__,' ${WRKSRC}/Makefile

#regression-test:
#		cd ${WRKSRC}; env ${MAKE_ENV} ${GMAKE} test

.include <bsd.port.post.mk>
