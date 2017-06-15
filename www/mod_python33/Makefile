# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mod_python
PORTVERSION=	3.3.1
PORTREVISION=	8
CATEGORIES=	www python
MASTER_SITES=	APACHE_HTTPD/modpython
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	33
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

LICENSE=	APACHE20

CONFLICTS_INSTALL=	ap2[24]-mod_python3[^3]*

USE_APACHE=	22
USES=		cpe python:2.7 tar:tgz
CPE_VENDOR=	apache

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs="${APXS}"		\
			--with-python="${PYTHON_CMD}"	\
			--without-flex

LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS+=	APXS=${APXS}
MAKE_ENV=	EXPR_COMPAT=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER}

# You need to install apache & mod_python before you run this
regression-test: build
	-@${MAKE} check -C ${WRKSRC}

.include <bsd.port.mk>
