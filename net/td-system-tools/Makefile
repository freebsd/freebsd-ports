PORTNAME=	td-system-tools
DISTVERSION=	1.5.6
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/system-tools/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Printing basic system information and system maintenance
WWW=		https://www.nntb.no/~dreibh/system-tools/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		cmake tar:xz
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man

.include <bsd.port.mk>
