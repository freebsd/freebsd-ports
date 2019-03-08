# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	john
# NB: starting from the next version, community-enhanced (jumbo) patch
# should be offered as an option (suggested by Solar Designer himself).
DISTVERSION=	1.8.0-jumbo-1
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/j/ \
		http://mirrors.kernel.org/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://distro.ibiblio.org/openwall/projects/john/${DISTVERSION:C/-.*//}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp

BROKEN_aarch64=	cannot detect CPU architecture
BROKEN_mips64=	cannot detect CPU architecture

USES=		gmake shebangfix ssl tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS_EXTRA="-DJOHN_SYSTEMWIDE=1" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
SHEBANG_FILES=	../run/*.pl ../run/*.rb ../run/benchmark-unify ../run/relbench
WRKSRC_SUBDIR=	src

ALL_TARGET=	default

BINARIES=	calc_stat cprepair genmkvpwd john luks2john mkvcalcproba \
		raw2dyna SIPdump tgtsnarf uaf2john vncpcap2john wpapcap2john

BINLINKS=	base64conv dmg2john gpg2john hccap2john keepass2john \
		keychain2john keyring2john keystore2john kwallet2john \
		putty2john pwsafe2john racf2john rar2john \
		truecrypt_volume2john unafs undrop unique unshadow zip2john

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS #OPENMP
#OPENMP_USES=	compiler:openmp

post-extract:
	@${RM} ${WRKSRC}/pfx_fmt_plug.c ${WRKSRC}/rawSHA0_fmt_plug.c \
		${WRKSRC}/ssh_fmt_plug.c \

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/params.h
# Replace methods and types that were marked deprecated by OpenSSL 0.9.7
# and removed in OpenSSL 1.1.0 and LibreSSL
	@${REINPLACE_CMD} -e 's|des_string_to_key|DES_string_to_key|' \
		${WRKSRC}/KRB4_fmt_plug.c
	@${REINPLACE_CMD} -e 's|des_set_odd_parity|DES_set_odd_parity|' \
		${WRKSRC}/KRB4_std_plug.c
	@${REINPLACE_CMD} -e 's|C_Block|DES_cblock|' \
		${WRKSRC}/efs_fmt_plug.c \
		${WRKSRC}/gpg_fmt_plug.c \
		${WRKSRC}/keychain_fmt_plug.c \
		${WRKSRC}/mozilla_ng_fmt_plug.c \
		${WRKSRC}/opencl_gpg_fmt_plug.c \
		${WRKSRC}/opencl_keychain_fmt_plug.c \
		${WRKSRC}/ssh_ng_fmt_plug.c

do-install:
.for b in ${BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/../run/${b} ${STAGEDIR}${PREFIX}/bin
.endfor
.for l in ${BINLINKS}
	${LN} -sf john ${STAGEDIR}${PREFIX}/bin/${l}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/extra
	cd ${WRKSRC}/../run && ${INSTALL_DATA} *.chr *.conf *.lst \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/../run && ${INSTALL_DATA} *.?? benchmark-unify \
		dictionary.rfc2865 john.*sh_completion mailer makechr \
		relbench stats ${STAGEDIR}${DATADIR}/extra

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${RM} ${WRKSRC}/../doc/COPYING
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
