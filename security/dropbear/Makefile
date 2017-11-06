# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	dropbear
PORTVERSION=	2017.75
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	pkubaj@anongoth.pl
COMMENT=	SSH 2 server, designed to be usable in small memory environments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		cpe gmake tar:bzip2
CPE_VENDOR=	matt_johnston
CPE_PRODUCT=	dropbear_ssh_server

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DH_GROUP1 SMALL_CODE STATIC
OPTIONS_DEFAULT=	AES128 AES256 CTR RSA SHA2_256 SHA2_512 SMALL_CODE TWOFISH128 TWOFISH256
OPTIONS_MULTI=	ENC KEY MAC MODE
OPTIONS_MULTI_ENC=	AES128 3DES AES256 BLOWFISH TWOFISH256 TWOFISH128
OPTIONS_MULTI_MODE=	CBC CTR
OPTIONS_MULTI_KEY=	ECDSA DSA RSA
OPTIONS_MULTI_MAC=	MD5 SHA1 SHA1_96 SHA2_256 SHA2_512

3DES_DESC=	Enable 3DES-based encryption
3DES_IMPLIES=	CTR
AES128_DESC=	Enable AES128-based encryption
AES256_DESC=	Enable AES256-based encryption
TWOFISH128_DESC=	Enable Twofish128-based encryption
TWOFISH256_DESC=	Enable Twofish256-based encryption
BLOWFISH_DESC=	Enable Blowfish-based encryption

DH_GROUP1_DESC=	Enable Group1 Diffie-Hellman (less secure)

CBC_DESC=	Use CBC mode for ciphers (less secure)
CTR_DESC=	Use CTR mode for ciphers (more secure)

ECDSA_DESC=	Enable ECDSA public key support
DSA_DESC=	Enable DSA public key support
RSA_DESC=	Enable RSA public key support

MD5_DESC=	Enable MD5 MAC (broken)
SHA1_DESC=	Enable SHA1 MAC (less secure)
SHA1_96_DESC=	Enable SHA1_96 MAC (less secure)
SHA2_256_DESC=	Enable SHA2_256 MAC
SHA2_512_DESC=	Enable SHA2_512 MAC

SMALL_CODE_DESC=	Make binary smaller in exchange for 50% performance hit

STATIC_LDFLAGS=	-static

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${LOCALBASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in

post-patch-SMALL_CODE-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SMALL_CODE/d" \
		${WRKSRC}/options.h

post-patch-3DES-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_3DES/d" \
		${WRKSRC}/options.h

post-patch-AES128-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_AES128/d" \
		${WRKSRC}/options.h

post-patch-AES256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_AES256/d" \
		${WRKSRC}/options.h

post-patch-TWOFISH256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_TWOFISH256/d" \
		${WRKSRC}/options.h

post-patch-TWOFISH128-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_TWOFISH128/d" \
		${WRKSRC}/options.h

post-patch-BLOWFISH-on:
	@${REINPLACE_CMD} -e "s,/\*#define DROPBEAR_BLOWFISH\*/,#define DROPBEAR_BLOWFISH,g" \
		${WRKSRC}/options.h

post-patch-CBC-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ENABLE_CBC_MODE/d" \
		${WRKSRC}/options.h

post-patch-CTR-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ENABLE_CTR_MODE/d" \
		${WRKSRC}/options.h

post-patch-DH_GROUP1-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DH_GROUP1 1/d" \
		${WRKSRC}/options.h

post-patch-DSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_DSS/d" \
		${WRKSRC}/options.h

post-patch-RSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_RSA/d" \
		${WRKSRC}/options.h

post-patch-ECDSA-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_ECDSA/d" \
		${WRKSRC}/options.h

post-patch-MD5-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_MD5_HMAC/d" \
		${WRKSRC}/options.h

post-patch-SHA1-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA1_HMAC/d" \
		${WRKSRC}/options.h

post-patch-SHA1_96-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA1_96_HMAC/d" \
		${WRKSRC}/options.h

post-patch-SHA2_256-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA2_256_HMAC/d" \
		${WRKSRC}/options.h

post-patch-SHA2_512-off:
	@${REINPLACE_CMD} -e "/#define DROPBEAR_SHA2_512_HMAC/d" \
		${WRKSRC}/options.h

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dropbear
	${INSTALL_PROGRAM} ${WRKSRC}/dbclient ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbearkey ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dropbear ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dropbearconvert.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbearkey.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dbclient.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dropbear.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
