# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-mbedtls

COMMENT=		Secure IP/Ethernet tunnel daemon, mbedTLS-based build

OPTIONS_EXCLUDE=	OPENSSL PKCS11 X509ALTUSERNAME
OPTIONS_SLAVE=		MBEDTLS

MASTERDIR=		${.CURDIR}/../../security/openvpn

.include "${MASTERDIR}/Makefile"
