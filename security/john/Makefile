# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	john
DISTVERSION=	1.8.0-jumbo-1
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/j/ \
		http://mirrors.kernel.org/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://distro.ibiblio.org/pub/linux/distributions/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://gd.tuwien.ac.at/opsys/linux/openwall/projects/john/${DISTVERSION:C/-.*//}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

LICENSE=	GPLv2

BROKEN_SSL=	openssl-devel

LIB_DEPENDS=	libgmp.so:math/gmp

BROKEN_aarch64=	Fails to build: Cannot detect CPU architechture
BROKEN_mips64=	Fails to build: Cannot detect CPU architechture

USES=		gmake shebangfix ssl tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
SHEBANG_FILES=	../run/*.pl ../run/*.rb ../run/benchmark-unify ../run/relbench
WRKSRC_SUBDIR=	src

ALL_TARGET=	default
CFLAGS+=	-DJOHN_SYSTEMWIDE=1 \
		-DJOHN_SYSTEMWIDE_HOME=\\\"${DATADIR}\\\" \
		-DJOHN_SYSTEMWIDE_EXEC=\\\"${LOCALBASE}/libexec/${PORTNAME}\\\"

# We prefer -jumbo (community-enhanced) versions instead of vanilla releases
# due to the sad fact that `-jumbo-???' suffixed versions *precede* official
# ones per pkg_version(1) -t check.  So, when Alexander rolls out new "plain"
# release, just hold the horses and wait for corresponding -jumbo one, which
# usually does not take too long to appear.
#
PORTSCOUT=	limit:.*-jumbo

BINARIES=	calc_stat cprepair genmkvpwd john luks2john mkvcalcproba \
		raw2dyna SIPdump tgtsnarf uaf2john vncpcap2john wpapcap2john

BINLINKS=	base64conv dmg2john gpg2john hccap2john keepass2john \
		keychain2john keyring2john keystore2john kwallet2john \
		pfx2john putty2john pwsafe2john racf2john rar2john ssh2john \
		truecrypt_volume2john unafs undrop unique unshadow zip2john

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS #OPENMP
#OPENMP_USES=	compiler:openmp

post-patch:
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
