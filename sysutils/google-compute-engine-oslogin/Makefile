# $FreeBSD$

PORTNAME=	google-compute-engine-oslogin
DISTVERSION=	20191018.00
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OS Login Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/packaging/debian/copyright

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	gsed:textproc/gsed \
		${LOCALBASE}/lib/pam_mkhomedir.so:security/pam_mkhomedir

USES=		compiler:c++11-lang gmake localbase:ldflags
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	guest-oslogin
GH_TAGNAME=	5a710bb

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

MAKE_ARGS=	CPPFLAGS="-Iinclude -I${LOCALBASE}/include/json-c -I${LOCALBASE}/include" \
		LDLIBS="-lcurl -ljson-c -L${LOCALBASE}/lib" \
		DESTDIR=${STAGEDIR}${PREFIX} \
		PREFIX=${PREFIX} \
		LIBDIR=${PREFIX}/lib \
		PAMDIR=${PREFIX}/lib \
		MANDIR=${PREFIX}/man

post-install:
	${LN} -sf libnss_oslogin-${DISTVERSION}.so ${STAGEDIR}${PREFIX}/lib/nss_oslogin.so.1
	${LN} -sf libnss_cache_oslogin-${DISTVERSION}.so ${STAGEDIR}${PREFIX}/lib/nss_cache_oslogin.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/google_authorized_keys \
		${STAGEDIR}${PREFIX}/lib/libnss_oslogin-${DISTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libnss_cache_oslogin-${DISTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/pam_oslogin_admin.so \
		${STAGEDIR}${PREFIX}/lib/pam_oslogin_login.so

.include <bsd.port.mk>
