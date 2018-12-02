# Created by: Serguei Okladnikov <oklaspec@gmail.com>
# $FreeBSD$

PORTNAME=	qjsonrpc
PORTVERSION=	1.0.2
CATEGORIES=	net www devel
MASTER_SITES=	http://bitbucket.org/devonit/qjsonrpc/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	oklaspec@gmail.com
COMMENT=	C++ Qt based JSON RPC2 library

LICENSE=	LGPL21

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		moc_build network qtestlib_build rcc_build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/devonit-qjsonrpc-adefe89b0c6f

post-configure:
	@${REINPLACE_CMD} 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
