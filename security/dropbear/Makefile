# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dropbear
PORTVERSION=	2019.78
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
CONFIGURE_ARGS=	--disable-harden
USE_RC_SUBR=	${PORTNAME}
ALL_TARGET=	all scp

OPTIONS_DEFINE=		SMALL_CODE STATIC
OPTIONS_DEFAULT=	AES128 AES256 CTR CURVE25519 GROUP14_SHA256 GROUP16 RSA SHA2_256 TWOFISH128 TWOFISH256
OPTIONS_MULTI=		ENC KEY KEX MAC MODE
OPTIONS_MULTI_ENC=	3DES AES128 AES256 BLOWFISH TWOFISH128 TWOFISH256
OPTIONS_MULTI_KEY=	ECDSA DSA RSA
OPTIONS_MULTI_KEX=	CURVE25519 ECDH GROUP1 GROUP14_SHA1 GROUP14_SHA256 GROUP16
OPTIONS_MULTI_MAC=	MD5 SHA1 SHA1_96 SHA2_256
OPTIONS_MULTI_MODE=	CBC CTR

3DES_DESC=		Enable 3DES-based encryption
AES128_DESC=		Enable AES128-based encryption
AES256_DESC=		Enable AES256-based encryption
BLOWFISH_DESC=		Enable Blowfish-based encryption
CBC_DESC=		Use CBC mode for ciphers (less secure)
CTR_DESC=		Use CTR mode for ciphers (more secure)
CURVE25519_DESC=	Enable Curve25519
DSA_DESC=		Enable DSA public key support
ECDH_DESC=		Enable ECDH (insecure)
ECDSA_DESC=		Enable ECDSA public key support
GROUP14_SHA1_DESC=	Enable Group14 Diffie-Helman with SHA1 (insecure)
GROUP14_SHA256_DESC=	Enable Group14 Diffie-Helman with SHA256
GROUP16_DESC=		Enable Group16 Diffie-Hellman
GROUP1_DESC=		Enable Group1 Diffie-Hellman (insecure)
MD5_DESC=		Enable MD5 MAC (broken)
RSA_DESC=		Enable RSA public key support
SHA1_96_DESC=		Enable SHA1_96 MAC (less secure)
SHA1_DESC=		Enable SHA1 MAC (less secure)
SHA2_256_DESC=		Enable SHA2_256 MAC
SMALL_CODE_DESC=	Make binary smaller in exchange for 50% performance hit
TWOFISH128_DESC=	Enable Twofish128-based encryption
TWOFISH256_DESC=	Enable Twofish256-based encryption

3DES_IMPLIES=	CTR
CBC_IMPLIES=	CTR

STATIC_CONFIGURE_ENABLE=	static

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/default_options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

post-patch-SMALL_CODE-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SMALL_CODE/d" \
		${WRKSRC}/default_options.h

post-patch-3DES-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_3DES/d" \
		${WRKSRC}/default_options.h

post-patch-AES128-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_AES128/d" \
		${WRKSRC}/default_options.h

post-patch-AES256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_AES256/d" \
		${WRKSRC}/default_options.h

post-patch-TWOFISH256-on:
	@${REINPLACE_CMD} -e "s,#define DROPBEAR_TWOFISH256 0,#define DROPBEAR_TWOFISH256 1,g" \
		${WRKSRC}/default_options.h

post-patch-TWOFISH128-on:
	@${REINPLACE_CMD} -e "s,#define DROPBEAR_TWOFISH128 0,#define DROPBEAR_TWOFISH128 1,g" \
		${WRKSRC}/default_options.h

post-patch-BLOWFISH-on:
	@${REINPLACE_CMD} -e "s,#define DROPBEAR_BLOWFISH 0,#define DROPBEAR_BLOWFISH 1,g" \
		${WRKSRC}/default_options.h

post-patch-CBC-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ENABLE_CBC_MODE/d" \
		${WRKSRC}/default_options.h

post-patch-CTR-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ENABLE_CTR_MODE/d" \
		${WRKSRC}/default_options.h

post-patch-CURVE25519-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_CURVE25519 1/d" \
		${WRKSRC}/default_options.h

post-patch-ECDH-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ECDH 1/d" \
		${WRKSRC}/default_options.h

post-patch-GROUP1-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DH_GROUP1 1/d" \
		${WRKSRC}/default_options.h

post-patch-GROUP14_SHA1-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DH_GROUP14_SHA1 1/d" \
		${WRKSRC}/default_options.h

post-patch-GROUP14_SHA256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DH_GROUP14_SHA256 1/d" \
		${WRKSRC}/default_options.h

post-patch-GROUP16-on:
	@${REINPLACE_CMD} -e "s,#define DROPBEAR_DH_GROUP16 0,#define DROPBEAR_DH_GROUP16 1,g" \
		${WRKSRC}/default_options.h

post-patch-DSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DSS/d" \
		${WRKSRC}/default_options.h

post-patch-RSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_RSA/d" \
		${WRKSRC}/default_options.h

post-patch-ECDSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ECDSA/d" \
		${WRKSRC}/default_options.h

post-patch-MD5-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_MD5_HMAC/d" \
		${WRKSRC}/default_options.h

post-patch-SHA1-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA1_HMAC/d" \
		${WRKSRC}/default_options.h

post-patch-SHA1_96-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA1_96_HMAC/d" \
		${WRKSRC}/default_options.h

post-patch-SHA2_256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA2_256_HMAC/d" \
		${WRKSRC}/default_options.h

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
