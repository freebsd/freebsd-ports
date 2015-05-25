# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt5
PORTVERSION=	1432320409
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt5 Utilities

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		py27-sphinx-intl>=0:${PORTSDIR}/textproc/py-sphinx-intl \
		py27-sphinxcontrib-httpdomain>=0:${PORTSDIR}/textproc/py-sphinxcontrib-httpdomain \
		tex-formats>=0:${PORTSDIR}/print/tex-formats \
		tex-dvipsk>=0:${PORTSDIR}/print/tex-dvipsk
RUN_DEPENDS=	pc-updatemanager:${PORTSDIR}/sysutils/pcbsd-utils \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		cdda2wav:${PORTSDIR}/sysutils/cdrtools
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpoppler-qt5.so:${PORTSDIR}/graphics/poppler-qt5

CONFLICTS?=	pcbsd-utils-qt4-[0-9]*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS=	amd64
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras
USES=		qmake tar:xz python desktop-file-utils

WRKSRC=		${WRKDIR}/src-qt5

QMAKE_ARGS=	CONFIG+="configure"

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/share/pcbsd/doc/html -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
