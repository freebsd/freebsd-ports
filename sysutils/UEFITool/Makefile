# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	UEFITool
DISTVERSIONPREFIX=	A
DISTVERSION=	49
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	UEFI images parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

USES=		qmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	LongSoft
USE_GL=		gl
USE_QT5=	core gui widgets buildtools_build qmake_build

WRKSRC_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
