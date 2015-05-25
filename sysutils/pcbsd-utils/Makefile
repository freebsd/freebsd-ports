# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-utils
PORTVERSION=	1432134849
CATEGORIES=	sysutils
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD Command-Line Utilities

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	sipcalc:${PORTSDIR}/net-mgmt/sipcalc \
		eject:${PORTSDIR}/sysutils/eject \
		unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/pcbsd-utils
USE_QT5=	core network buildtools qmake
USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
