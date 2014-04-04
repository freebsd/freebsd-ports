# Created by: Serguei Okladnikov <oklaspec@gmail.com>
# $FreeBSD$

PORTNAME=	qjsonrpc
PORTVERSION=	1.0.1
CATEGORIES=	net www devel
MASTER_SITES=	http://bitbucket.org/devonit/qjsonrpc/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	oklaspec@gmail.com
COMMENT=	C++ Qt based JSON RPC2 library

LICENSE=	LGPL21

USES=		qmake
USE_QT4=	moc_build network qtestlib_build rcc_build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/devonit-qjsonrpc-b138256fe2b8

post-configure:
	@${REINPLACE_CMD} 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
