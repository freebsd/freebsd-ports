# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkml
PORTVERSION=	1.2
DISTVERSIONPREFIX=	release-
PORTREVISION=	5
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parse, generate, and operate on KML

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	curl-config:ftp/curl \
		${LOCALBASE}/include/expat.h:textproc/expat2
LIB_DEPENDS=	liburiparser.so:net/uriparser

OPTIONS_DEFINE=	SWIG

CONFIGURE_ARGS=	--disable-java --disable-python
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		autoreconf gmake libtool localbase

GH_ACCOUNT=	google
USE_GITHUB=	yes

SWIG_BUILD_DEPENDS=	swig:devel/swig13
SWIG_CONFIGURE_OFF=	--disable-swig

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am -exec ${REINPLACE_CMD} 's|-Werror||; s| -ansi -pedantic||' '{}' \;

.include <bsd.port.mk>
