# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pcbsd-sysadm
PORTVERSION=	20151217
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	PC-BSD SysAdm API server

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	sipcalc:${PORTSDIR}/net-mgmt/sipcalc \
		eject:${PORTSDIR}/sysutils/eject \
		unzip:${PORTSDIR}/archivers/unzip

WRKSRC_SUBDIR=	src
USE_QT5=	core network buildtools qmake
USES=		pkgconfig tar:xz qmake
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	sysadm
GH_TAGNAME=	5583f4d2c00d8326b44f7d39eefd0a90276d7a74

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
