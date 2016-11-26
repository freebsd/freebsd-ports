# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkml
PORTVERSION=	1.2
DISTVERSIONPREFIX=	release-
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for parse, generate, and operate on KML

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl-config:ftp/curl
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		liburiparser.so:net/uriparser

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
