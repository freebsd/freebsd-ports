#
# Ports collection makefile for:	py-lucene
# Date created:				Nov 2, 2006
# Whom:					Frank J. Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	PyLucene
PORTVERSION=	2.0.0
PORTREVISION=	3
CATEGORIES=	textproc devel python
MASTER_SITES=	http://downloads.osafoundation.org/PyLucene/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}${PATCHSET}

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	A GCJ-compiled version of Java Lucene integrated with Python

BUILD_DEPENDS+=	${LOCALBASE}/bin/gcj41:${PORTSDIR}/lang/gcc41

USE_PYTHON=	2.4+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
PATCHSET=	-8

OPTIONSFILE?=	${PORT_DBDIR}/${PORTNAME}/options

OPTIONS=	BDB "Compile with support for Berkley DB" Off

.include <bsd.port.pre.mk>

_GCC_LIBDIR!=	(cd ${PORTSDIR}/lang/gcc41;make -V TARGLIB)
GCC_LIBDIR=	${_GCC_LIBDIR:S/${PREFIX}/${LOCALBASE}/}

MAKE_ARGS+=	PREFIX=${PREFIX} PREFIX_PYTHON=${LOCALBASE} GCJ_HOME=${LOCALBASE} \
		GCJ_LIBDIR=${GCC_LIBDIR} CC=${LOCALBASE}/bin/gcc41 CXX=${LOCALBASE}/bin/g++41 \
		JCC=${LOCALBASE}/bin/gcj41 JCCH=${LOCALBASE}/bin/gcjh41 PYTHON=${PYTHON_CMD} \
		LDFLAGS+=-L${LOCALBASE}/lib PYTHON_INC=${PYTHON_INCLUDEDIR} \
		PYTHON_SITE=${PYTHON_SITELIBDIR}

.if defined(WITH_BDB)
BROKEN=		Will not compile with BDB support
REAL_BDB_VER=	${BDB_VER:C/([0-9])([0-9])/\1.\2/g}
_BDB_WRKSRC!=	(cd ../../databases/db44;make -V WRKSRC)
BDB_WRKSRC=	${_BDB_WRKSRC:S/\/build_unix//}
MAKE_ARGS+=	DB=${BDB_WRKSRC} PREFIX_DB=${LOCALBASE} DB_VER=${REAL_BDB_VER} DB_LIB_VER=${REAL_BDB_VER}
USE_BDB=	44
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/databases/db44:extract
.endif

.include <bsd.port.post.mk>
