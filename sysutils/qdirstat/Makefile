# $FreeBSD$

PORTNAME=	qdirstat
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Qt utility that sums up disk usage for directory trees

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang desktop-file-utils gl qmake qt:5 shebangfix
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	shundhammer

SHEBANG_FILES=	scripts/qdirstat-cache-writer

QMAKE_ARGS+=	INSTALL_PREFIX=${PREFIX}

pre-configure:
	${REINPLACE_CMD} -e 's,/share,,g' \
		${WRKSRC}/man/man.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qdirstat

.include <bsd.port.mk>
