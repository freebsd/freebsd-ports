# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt5
PORTVERSION=	1444236547
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt5 Utilities

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sphinx-intl>=0:textproc/py-sphinx-intl \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-httpdomain>=0:textproc/py-sphinxcontrib-httpdomain \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme \
		${PYTHON_PKGNAMEPREFIX}alabaster>=0:textproc/py-alabaster \
		tex-formats>=0:print/tex-formats \
		tex-dvipsk>=0:print/tex-dvipsk
RUN_DEPENDS=	pc-updatemanager:sysutils/pcbsd-utils \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus \
		cdda2wav:sysutils/cdrtools
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpoppler-qt5.so:graphics/poppler-qt5

CONFLICTS?=	pcbsd-utils-qt4-[0-9]*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS=	amd64
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras
USES=		desktop-file-utils python qmake shebangfix tar:xz
SHEBANG_FILES=	pc-netmanager/src/NetworkManager/resources/umts_stick \
		pc-sysmanager/scripts/fastest_cvsup

WRKSRC_SUBDIR=	src-qt5

QMAKE_ARGS=	CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	pcbsd
GH_TAGNAME=	3c4d2b

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/share/pcbsd/doc/html -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
