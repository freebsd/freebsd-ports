PORTNAME=	UEFITool
DISTVERSIONPREFIX=	A
DISTVERSION=	73
CATEGORIES=	sysutils

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	UEFI images parser
WWW=		https://github.com/LongSoft/UEFITool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.md

USES=		compiler:c++11-lang gl qmake:outsource qt:6
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		base

WRKSRC_SUBDIR=	${PORTNAME}
GH_ACCOUNT=	LongSoft

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
