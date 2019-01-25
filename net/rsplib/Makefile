# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>
# $FreeBSD$

PORTNAME=	rsplib
PORTVERSION=	3.2.0
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/rserpool/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	RSerPool Framework and Example Applications

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang qt:5 shebangfix
USE_LDCONFIG=	yes
USE_QT=		core gui widgets xml buildtools_build qmake_build

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man \
		-DDOCSDIR=${DOCSDIR}
CMAKE_ON=	ENABLE_CSP ENABLE_QT USE_KERNEL_SCTP
SHEBANG_FILES=	src/scriptingserviceexample

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
