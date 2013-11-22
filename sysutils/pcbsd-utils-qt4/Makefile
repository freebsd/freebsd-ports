# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils-qt4
PORTVERSION=	1382605460
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Qt 4 Utilities

RUN_DEPENDS=	pc-metapkgmanager:${PORTSDIR}/sysutils/pcbsd-utils
LIB_DEPENDS=	libQtSolutions_SingleApplication-head.so:${PORTSDIR}/devel/qt4-qtsolutions-singleapplication \
		libcurl.so:${PORTSDIR}/ftp/curl

MAKE_JOBS_UNSAFE=yes
USE_CDRTOOLS=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_QT4=	corelib gui network svg \
		moc_build rcc_build uic_build
USES=		qmake

WRKSRC=		${WRKDIR}/src-qt4

QMAKE_ARGS+=	CONFIG+="configure"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900030
IGNORE=		requires FreeBSD 9.0 or later
.endif

.include <bsd.port.post.mk>
