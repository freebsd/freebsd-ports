# Created by: Matthias Andree <mandree@FreeBSD.org>

PKGNAMESUFFIX=		-mbedtls

COMMENT=		Secure IP/Ethernet tunnel daemon, mbedTLS-based build

DEPRECATED=		mbedTLS lacks TLSv1.3 and OpenVPN-mbedtls does not work on FreeBSD 14-CURRENT
EXPIRATION_DATE=	2022-03-31

CONFLICTS_INSTALL=	openvpn openvpn-beta openvpn-devel

OPTIONS_EXCLUDE=	OPENSSL PKCS11 X509ALTUSERNAME
OPTIONS_SLAVE=		MBEDTLS

MASTERDIR=		${.CURDIR}/../../security/openvpn

.include "${MASTERDIR}/Makefile"
