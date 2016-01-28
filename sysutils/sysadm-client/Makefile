# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysadm-client
PORTVERSION=	1454017085
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	SysAdm Qt5 Client

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src-qt5
USE_QT5=	core buildtools gui network qmake websockets widgets
USES=		pkgconfig tar:xz qmake
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd
GH_PROJECT=	sysadm-ui-qt
GH_TAGNAME=	172499222109c0e4aa29e63600a5a54ff3fa553e
PLIST_FILES+=	bin/sysadm-client

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
IGNORE=		requires FreeBSD 10 or later
.endif

.include <bsd.port.post.mk>
