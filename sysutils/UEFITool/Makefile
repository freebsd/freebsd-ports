# Created by: Piotr Kubaj <pkubaj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	UEFITool
DISTVERSIONPREFIX=	A
DISTVERSION=	57
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	UEFI images parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

USES=		compiler:c++11-lang gl qmake:outsource qt:5
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		core gui widgets buildtools_build qmake_build

WRKSRC_SUBDIR=	${PORTNAME}
GH_ACCOUNT=	LongSoft

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
