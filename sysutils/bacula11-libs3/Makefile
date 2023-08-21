PORTNAME=	bacula11-libs3
PORTVERSION=	20200523
CATEGORIES=	sysutils
MASTER_SITES=	https://www.bacula.org/downloads/
DISTNAME=	libs3-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ml@netfence.it
COMMENT=	Bacula libs3
WWW=		https://www.bacula.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libcurl.so:ftp/curl

MAKEFILE=	GNUmakefile
MAKE_ARGS=	MYDESTDIR=${STAGEDIR}/${PREFIX} \
		MYINSTALL=install
USES=		compiler:gcc-c++11-lib gmake gnome ssl
USE_GNOME+=	libxml2

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/s3
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/libs3.so.4.1.bac

.include <bsd.port.mk>
