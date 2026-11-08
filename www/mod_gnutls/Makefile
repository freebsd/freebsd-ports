PORTNAME=	mod_gnutls
DISTVERSION=	0.13.0
CATEGORIES=	www security
MASTER_SITES=	https://github.com/airtower-luna/${PORTNAME}/releases/download/${PORTNAME}/${DISTVERSION}/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Extension for Apache httpd using GnuTLS library to provide HTTPS
WWW=		https://github.com/airtower-luna/mod_gnutls

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libgnutls.so:security/gnutls
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3.13:devel/py-pyyaml@${PY_FLAVOR}

USES=		apache compiler:c11 cpe meson pkgconfig python:build,test \
		tar:bzip2
CPE_VENDOR=	${PORTNAME}_project

MESON_ARGS=	-Dapxs-bin=${APXS} \
		-Dpdf-doc=false

BINARY_ALIAS=	python3=${PYTHON_CMD} python=${PYTHON_CMD}

DBDIR=		${PREFIX}/var/db/${PORTNAME}
PLIST_SUB=	SED="${SED}" WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
SUB_FILES=	pkg-message
SUB_LIST=	DBDIR="${DBDIR}"

post-install:
	${MKDIR} "${STAGEDIR}${DBDIR}"

.include <bsd.port.mk>
