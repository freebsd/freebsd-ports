# $FreeBSD$

PORTNAME=	google-compute-engine-oslogin
DISTVERSION=	1.1.5
CATEGORIES=	sysutils

MAINTAINER=	helen.koike@collabora.com
COMMENT=	OS Login Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	gsed:textproc/gsed \
		${LOCALBASE}/lib/pam_mkhomedir.so:security/pam_mkhomedir

USES=		gmake
USE_LDCONFIG=	yes
USE_GCC=	any
USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	compute-image-packages
GH_TAGNAME=	20180227
MAKE_ARGS=	JSON_INCLUDE_PATH=${LOCALBASE}/include/json-c \
		BIN_INSTALL_PATH=/bin \
		PAM_INSTALL_PATH=/lib \
		AUTHKEYS_INSTALL_PATH=/bin \
		NSS_LIBRARY_SONAME=nss_oslogin.so.1

WRKSRC_SUBDIR=	google_compute_engine_oslogin

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/sudoers.d|${PREFIX}/etc/sudoers.d|g ; \
		s|/usr/bin|${PREFIX}/bin|g' ${WRKSRC}/bin/google_oslogin_control

post-install:
	${LN} -sf libnss_${PORTNAME}-${DISTVERSION}.so ${STAGEDIR}${PREFIX}/lib/nss_oslogin.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/google_authorized_keys \
		${STAGEDIR}${PREFIX}/lib/libnss_google-compute-engine-oslogin-${DISTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/pam_oslogin_admin.so \
		${STAGEDIR}${PREFIX}/lib/pam_oslogin_login.so

.include <bsd.port.mk>
