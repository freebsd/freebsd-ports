# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface for XSLT C library for GNOME

MASTERDIR=	${.CURDIR}/../libxslt
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

USES=		pathfix
USE_GNOME=	lthack libxslt
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--with-python=${PYTHON_CMD}

DOCSDIR=	${PREFIX}/share/doc/py-libxslt
EXAMPLESDIR=	${PREFIX}/share/examples/py-libxslt

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
