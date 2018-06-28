# $FreeBSD$

PORTNAME=	qdirstat
PORTVERSION=	1.4
CATEGORIES=	sysutils

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Qt utility that sums up disk usage for directory trees

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	shundhammer

USES=		desktop-file-utils qmake qt:5 shebangfix
USE_GL=		gl
USE_QT=		buildtools_build core gui widgets
SHEBANG_FILES=	scripts/qdirstat-cache-writer

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
		${WRKSRC}/doc/doc.pro
	${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
		${WRKSRC}/doc/stats/stats.pro
	${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
		${WRKSRC}/scripts/scripts.pro
	${REINPLACE_CMD} -e 's,/bin/true,${TRUE},g' \
		${WRKSRC}/scripts/scripts.pro
	${REINPLACE_CMD} -e 's,/usr/,${PREFIX}/,g' \
		${WRKSRC}/src/src.pro

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qdirstat

.include <bsd.port.mk>
