# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface for XML parser library for GNOME

MASTERDIR=	${.CURDIR}/../libxml2
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USE_GNOME=	libxml2
USES=		python gettext-runtime
USE_PYTHON=	autoplist distutils

CPPFLAGS+=	`${PYTHON_CMD}-config --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib `${PYTHON_CMD}-config --libs`
CONFIGURE_ARGS=	--with-iconv=${ICONV_PREFIX} \
		--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--with-python=${PYTHON_CMD}

DOCSDIR=	${PREFIX}/share/doc/py-libxml2
EXAMPLESDIR=	${PREFIX}/share/examples/py-libxml2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/libxml2mod.so

.include "${MASTERDIR}/Makefile"
