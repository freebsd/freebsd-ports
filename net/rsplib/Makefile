# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	rsplib
PORTVERSION=	3.2.4
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/rserpool/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang qt:5 shebangfix tar:xz

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DDOCSDIR="${DOCSDIR}" \
		-DUSE_KERNEL_SCTP=1 -DENABLE_CSP=1 -DENABLE_QT=1
SHEBANG_FILES=	src/scriptingserviceexample
USE_LDCONFIG=	yes
USE_QT=		buildtools_build core gui qmake widgets xml

.include <bsd.port.mk>
