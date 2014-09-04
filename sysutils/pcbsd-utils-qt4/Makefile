# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt4
PORTVERSION=	1409841477
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt4 Utilities

RUN_DEPENDS=	lpreserver:${PORTSDIR}/sysutils/pcbsd-utils \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus
LIB_DEPENDS=	libQtSolutions_SingleApplication-head.so:${PORTSDIR}/devel/qt4-qtsolutions-singleapplication \
		libcurl.so:${PORTSDIR}/ftp/curl

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS=	amd64
USE_CDRTOOLS=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_QT4=	corelib gui network svg linguist \
		moc_build rcc_build uic_build
USES=		qmake tar:bzip2

WRKSRC=		${WRKDIR}/src-qt4

QMAKE_ARGS=	CONFIG+="configure"

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.mk>
