# $FreeBSD$

PORTNAME=	libxlsxwriter
PORTVERSION=	0.6.9
DISTVERSIONPREFIX=	RELEASE_
CATEGORIES=	math devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	C library for creating Excel XLSX files

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	jmcnamara

USE_LDCONFIG=	yes
USES=		gmake

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxlsxwriter.so.0
	${LN} -s libxlsxwriter.so.0 ${STAGEDIR}${PREFIX}/lib/libxlsxwriter.so

.include <bsd.port.mk>
