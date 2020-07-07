# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dropbear
PORTVERSION=	2020.80
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	SSH 2 server, designed to be usable in small memory environments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake tar:bzip2
CPE_VENDOR=	matt_johnston
CPE_PRODUCT=	dropbear_ssh_server

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
ALL_TARGET=	all scp

OPTIONS_DEFINE=		SMALL_CODE STATIC X11FWD
OPTIONS_DEFAULT=	AES128 AES256 CURVE25519 ED25519 GCM GROUP14_SHA256 \
			GROUP16 RSA SHA2_256
OPTIONS_MULTI=		ENC KEY KEX MAC MODE
OPTIONS_MULTI_ENC=	3DES AES128 AES256 CHACHA20POLY1305 TWOFISH128 \
			TWOFISH256
OPTIONS_MULTI_KEY=	ECDSA ED25519 DSA RSA
OPTIONS_MULTI_KEX=	CURVE25519 ECDH GROUP1 GROUP14_SHA1 GROUP14_SHA256 \
			GROUP16
OPTIONS_MULTI_MAC=	MD5 SHA1 SHA1_96 SHA2_256 SHA2_512
OPTIONS_MULTI_MODE=	CBC CTR GCM

3DES_DESC=		Enable 3DES-based encryption
AES128_DESC=		Enable AES128-based encryption
AES256_DESC=		Enable AES256-based encryption
CBC_DESC=		Use CBC mode for ciphers (less secure)
CHACHA20POLY1305_DESC=	Enable chacha20poly1305-based encryption
CTR_DESC=		Use CTR mode for ciphers
CURVE25519_DESC=	Enable Curve25519
DSA_DESC=		Enable DSA public key support
ECDH_DESC=		Enable ECDH (insecure)
ECDSA_DESC=		Enable ECDSA public key support
ED25519_DESC=		Enable ED25519 public key support
GCM_DESC=		Enable GCM mode for ciphers (more secure)
GROUP14_SHA1_DESC=	Enable Group14 Diffie-Helman with SHA1 (insecure)
GROUP14_SHA256_DESC=	Enable Group14 Diffie-Helman with SHA256
GROUP16_DESC=		Enable Group16 Diffie-Hellman
GROUP1_DESC=		Enable Group1 Diffie-Hellman (insecure)
MD5_DESC=		Enable MD5 MAC (broken)
RSA_DESC=		Enable RSA public key support
SHA1_96_DESC=		Enable SHA1_96 MAC (less secure)
SHA1_DESC=		Enable SHA1 MAC (less secure)
SHA2_256_DESC=		Enable SHA2_256 MAC
SHA2_512_DESC=		Enable SHA2_512 MAC
SMALL_CODE_DESC=	Make binary smaller in exchange for 50% performance hit
TWOFISH128_DESC=	Enable Twofish128-based encryption
TWOFISH256_DESC=	Enable Twofish256-based encryption
X11FWD_DESC=		Enable X11 forwarding

3DES_IMPLIES=	CTR
CBC_IMPLIES=	CTR

STATIC_CONFIGURE_ENABLE=	static

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/default_options.h

post-patch-SMALL_CODE-off:
	@${ECHO} "#define DROPBEAR_SMALL_CODE 0" >> ${WRKSRC}/localoptions.h

post-patch-3DES-on:
	@${ECHO} "#define DROPBEAR_3DES 1" >> ${WRKSRC}/localoptions.h

post-patch-AES128-off:
	@${ECHO} "#define DROPBEAR_AES128 0" >> ${WRKSRC}/localoptions.h

post-patch-AES256-off:
	@${ECHO} "#define DROPBEAR_AES256 0" >> ${WRKSRC}/localoptions.h

post-patch-CHACHA20POLY1305-off:
	@${ECHO} "#define DROPBEAR_CHACHA20POLY1305 0" >> ${WRKSRC}/localoptions.h

post-patch-TWOFISH256-on:
	@${ECHO} "#define DROPBEAR_TWOFISH256 1" >> ${WRKSRC}/localoptions.h

post-patch-TWOFISH128-on:
	@${ECHO} "#define DROPBEAR_TWOFISH128 1" >> ${WRKSRC}/localoptions.h

post-patch-CBC-on:
	@${ECHO} "#define DROPBEAR_ENABLE_CBC_MODE 1" >> ${WRKSRC}/localoptions.h

post-patch-CTR-off:
	@${ECHO} "#define DROPBEAR_ENABLE_CTR_MODE 0" >> ${WRKSRC}/localoptions.h

post-patch-GCM-on:
	@${ECHO} "#define DROPBEAR_ENABLE_GCM_MODE 1" >> ${WRKSRC}/localoptions.h

post-patch-CURVE25519-off:
	@${ECHO} "#define DROPBEAR_CURVE25519 0" >> ${WRKSRC}/localoptions.h

post-patch-ECDH-off:
	@${ECHO} "#define DROPBEAR_ECDH 0" >> ${WRKSRC}/localoptions.h

post-patch-GROUP1-off:
	@${ECHO} "#define DROPBEAR_DH_GROUP1 0" >> ${WRKSRC}/localoptions.h

post-patch-GROUP14_SHA1-off:
	@${ECHO} "#define DROPBEAR_DH_GROUP14_SHA1 0" >> ${WRKSRC}/localoptions.h

post-patch-GROUP14_SHA256-off:
	@${ECHO} "#define DROPBEAR_DH_GROUP14_SHA256 0" >> ${WRKSRC}/localoptions.h

post-patch-GROUP16-on:
	@${ECHO} "#define DROPBEAR_DH_GROUP16 1" >> ${WRKSRC}/localoptions.h

post-patch-DSA-off:
	@${ECHO} "#define DROPBEAR_DSS 0" >> ${WRKSRC}/localoptions.h

post-patch-RSA-off:
	@${ECHO} "#define DROPBEAR_RSA 0" >> ${WRKSRC}/localoptions.h

post-patch-ECDSA-off:
	@${ECHO} "#define DROPBEAR_ECDSA 0" >> ${WRKSRC}/localoptions.h

post-patch-ED25519-off:
	@${ECHO} "#define DROPBEAR_E25519 0" >> ${WRKSRC}/localoptions.h

post-patch-MD5-on:
	@${ECHO} "#define DROPBEAR_MD5_HMAC 1" >> ${WRKSRC}/localoptions.h

post-patch-SHA1-off:
	@${ECHO} "#define DROPBEAR_SHA1_HMAC 0" >> ${WRKSRC}/localoptions.h

post-patch-SHA1_96-off:
	@${ECHO} "#define DROPBEAR_SHA1_96_HMAC 0" >> ${WRKSRC}/localoptions.h

post-patch-SHA2_256-off:
	@${ECHO} "#define DROPBEAR_SHA2_256_HMAC 0" >> ${WRKSRC}/localoptions.h

post-patch-SHA2_512-on:
	@${ECHO} "#define DROPBEAR_SHA2_512_HMAC 1" >> ${WRKSRC}/localoptions.h

post-patch-X11FWD-on:
	@${ECHO} "#define DROPBEAR_X11FWD 1" >> ${WRKSRC}/localoptions.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dropbear
	${INSTALL_PROGRAM} ${WRKSRC}/dbclient ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearkey ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbear ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/scp ${STAGEDIR}${PREFIX}/bin/dbscp
	${INSTALL_MAN} ${WRKSRC}/dropbearconvert.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbearkey.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dbclient.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbear.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
