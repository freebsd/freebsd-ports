# $FreeBSD$

PKGNAMESUFFIX=	-gssapi
PORTREVISION=	7

COMMENT=	SASL GSSAPI authentication plugin

OPTIONS_SINGLE=			GSSAPI
OPTIONS_SINGLE_GSSAPI=		GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=		GSSAPI_BASE
GSSAPI_BASE_USES=		gssapi:base
GSSAPI_BASE_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_HEIMDAL_USES=		gssapi:heimdal,flags
GSSAPI_HEIMDAL_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=heimdal
GSSAPI_HEIMDAL_PLIST_FILES=	${LIBGS2_PLIST_FILES}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--enable-gssapi="${GSSAPIBASEDIR}" \
				--with-gss_impl=mit
GSSAPI_MIT_PLIST_FILES=		${LIBGS2_PLIST_FILES}

LIBGS2_PLIST_FILES=		lib/sasl2/libgs2.a \
				lib/sasl2/libgs2.so \
				lib/sasl2/libgs2.so.3 \
				lib/sasl2/libgs2.so.3.0.0

CYRUS_BUILD_TARGET=		gssapiv2

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
