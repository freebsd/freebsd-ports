# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>

PORTNAME=	td-system-tools
PORTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/system-tools/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	Printing basic system information and system maintenance

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		cmake tar:xz
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man

.include <bsd.port.mk>
