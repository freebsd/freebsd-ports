# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mod_python
PORTVERSION=	3.5.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://dist.modpython.org/dist/ \
		LOCAL/ohauer
MASTER_SITE_SUBDIR=	modpython
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	35
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module that embeds the Python interpreter within the server

LICENSE=	APACHE20

CONFLICTS_INSTALL=	ap2[24]-mod_python3[^5]*

USE_APACHE=	22+
USE_PYTHON=	yes
USES=		tar:tgz

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
	-@${MAKE} test -C ${WRKSRC}

.include <bsd.port.mk>
