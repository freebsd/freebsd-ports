# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkml
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parse, generate, and operate on KML

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/curl-config:${PORTSDIR}/ftp/curl \
		${LOCALBASE}/include/expat.h:${PORTSDIR}/textproc/expat2

CONFIGURE_ARGS=	--disable-java --disable-python --disable-swig \
		--with-expat-include-dir=${LOCALBASE}/include \
		--with-expat-lib-dir=${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool

post-patch:
	@${REINPLACE_CMD} -e '/SWIG_VERSION:4/ s|:4|#*.*.|' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} 's|-Werror||; s| -ansi -pedantic||' '{}' \;

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*

.include <bsd.port.mk>
