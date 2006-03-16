# Ports collection makefile for:  pear-gnupg
# Date created:			  16 March 2006
# Whom:				  mnag@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gnupg
PORTVERSION=	1.1
CATEGORIES=	security
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A pecl wrapper around the gpgme library

LIB_DEPENDS=	gpgme.15:${PORTSDIR}/security/gpgme

USE_PHP=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	gnupg

CONFIGURE_ARGS=	--with-gnupg=${LOCALBASE}/include/gpgme
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

PLIST_FILES=	%%EXAMPLESDIR%%/clearsign.php %%EXAMPLESDIR%%/decrypt.php \
		%%EXAMPLESDIR%%/encrypt.php %%EXAMPLESDIR%%/encryptsign.php \
		%%EXAMPLESDIR%%/export.php %%EXAMPLESDIR%%/import.php \
		%%EXAMPLESDIR%%/keyinfo.php %%EXAMPLESDIR%%/main.php \
		%%EXAMPLESDIR%%/verify.php
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 && ${PHP_VER} == 5
USE_GCC=	3.2+
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|\$$GNUPG_DIR/include|${LOCALBASE}/include/gpgme|" \
		-e "s|\$$GNUPG_DIR/lib|${LOCALBASE}/lib|" -e "s|-ldl||g" \
		${WRKSRC}/config.m4

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.php ${EXAMPLESDIR}

.include <bsd.port.post.mk>
