PORTNAME=	mod_gnutls
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	https://mod.gnutls.org/downloads/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Extension for Apache httpd using GnuTLS library to provide HTTPS
WWW=		https://mod.gnutls.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3.13:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libgnutls.so:security/gnutls

GNU_CONFIGURE=	yes
USES=		apache compiler:c++11-lang cpe libtool pkgconfig python tar:bzip2
CPE_VENDOR=	${PORTNAME}_project

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

DBDIR=		${PREFIX}/var/db/${PORTNAME}
PLIST_SUB=	SED="${SED}" WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
SUB_FILES=	pkg-message
SUB_LIST=	DBDIR="${DBDIR}"

CFLAGS+=	-Wno-deprecated-declarations -Wno-null-pointer-subtraction
CONFIGURE_ARGS=	--with-apxs="${APXS}"

INSTALL_TARGET=	install-strip

post-install:
	${MKDIR} "${STAGEDIR}${DBDIR}"

.include <bsd.port.mk>
