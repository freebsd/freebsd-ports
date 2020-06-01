# $FreeBSD$

PORTNAME=	libxlsxwriter
PORTVERSION=	0.9.5
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxlsxwriter.so.0
	${LN} -s libxlsxwriter.so.0 ${STAGEDIR}${PREFIX}/lib/libxlsxwriter.so

.include <bsd.port.mk>
