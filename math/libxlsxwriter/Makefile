PORTNAME=	libxlsxwriter
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	RELEASE_
CATEGORIES=	math devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	C library for creating Excel XLSX files

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jmcnamara
MAKE_ARGS=	INSTALL_DIR=${STAGEDIR}${PREFIX}

USE_LDCONFIG=	yes
USES=		compiler:c11 gmake

.include <bsd.port.mk>
