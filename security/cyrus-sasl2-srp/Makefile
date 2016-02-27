# $FreeBSD$

PKGNAMESUFFIX=	-srp

COMMENT=	SASL SRP authentication plugin

CONFIGURE_ARGS+=--enable-srp

OPTIONS_DEFINE=			SRP_SETPASS
OPTIONS_DEFAULT=		SRP_SETPASS
SRP_SETPASS_DESC=		setting SRP secrets with saslpasswd
SRP_SETPASS_CONFIGURE_ENABLE=	srp-setpass

PLIST_FILES=	lib/sasl2/libsrp.a \
		lib/sasl2/libsrp.so \
		lib/sasl2/libsrp.so.3 \
		lib/sasl2/libsrp.so.3.0.0

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
