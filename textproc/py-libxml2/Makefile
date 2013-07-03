# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface for XML parser library for GNOME

MASTERDIR=	${.CURDIR}/../libxml2
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME+=	libxml2
USE_PYTHON=	-2.7
CPPFLAGS+=	`${PYTHON_VERSION}-config --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib `${PYTHON_VERSION}-config --libs`
CONFIGURE_ARGS=	--with-iconv=${LOCALBASE} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--with-python=${PYTHON_CMD}

DOCSDIR=	${PREFIX}/share/doc/py-libxml2
EXAMPLESDIR=	${PREFIX}/share/examples/py-libxml2

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
