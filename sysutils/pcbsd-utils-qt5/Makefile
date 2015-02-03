# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt5
PORTVERSION=	1422974666
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt5 Utilities

LICENSE=	BSD

RUN_DEPENDS=	lpreserver:${PORTSDIR}/sysutils/pcbsd-utils \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus \
		cdda2wav:${PORTSDIR}/sysutils/cdrtools
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

CONFLICTS?=	pcbsd-utils-qt4-[0-9]*

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS=	amd64
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist \
		buildtools x11extras
USES=		qmake tar:xz python

WRKSRC=		${WRKDIR}/src-qt5

QMAKE_ARGS=	CONFIG+="configure"

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.mk>
