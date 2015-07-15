# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=		-polarssl

COMMENT=		Secure IP/Ethernet tunnel daemon, PolarSSL-based build

OPTIONS_EXCLUDE=	OPENSSL PKCS11 X509ALTUSERNAME
OPTIONS_SLAVE=		POLARSSL

MASTERDIR=		${.CURDIR}/../../security/openvpn

.include "${MASTERDIR}/Makefile"
