PORTNAME=	qdirstat
PORTVERSION=	2.0
CATEGORIES=	sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Qt utility that sums up disk usage for directory trees
WWW=		https://github.com/shundhammer/qdirstat

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang desktop-file-utils gettext-runtime gl qmake \
		qt:6 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	shundhammer
USE_GL=		gl
USE_QT=		5compat base

SHEBANG_FILES=	scripts/qdirstat-cache-writer

QMAKE_ARGS+=	INSTALL_PREFIX=${PREFIX}

LIBS+=		-lintl

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qdirstat

.include <bsd.port.mk>
