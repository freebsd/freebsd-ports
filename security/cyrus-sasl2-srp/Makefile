# $FreeBSD$

PKGNAMESUFFIX=	-srp

COMMENT=	SASL SRP authentication plugin

CYRUS_CONFIGURE_ARGS=	--enable-srp

OPTIONS_DEFINE=			SRP_SETPASS
OPTIONS_DEFAULT=		SRP_SETPASS
SRP_SETPASS_DESC=		setting SRP secrets with saslpasswd
SRP_SETPASS_CONFIGURE_ENABLE=	srp-setpass

.include "${.CURDIR}/../../security/cyrus-sasl2/Makefile.common"
