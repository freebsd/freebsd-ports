# Created by: David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	john
DISTVERSION=	1.7.9-jumbo-7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/g/ \
		http://mirrors.kernel.org/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://distro.ibiblio.org/pub/linux/distributions/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://gd.tuwien.ac.at/opsys/linux/openwall/projects/john/${DISTVERSION:C/-.*//}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

LICENSE=	GPLv2

USES=		gmake shebangfix tar:bzip2
SHEBANG_FILES=	run/*.pl
USE_OPENSSL=	yes
BUILD_WRKSRC=	${WRKDIR}/${DISTNAME}/src

# We prefer -jumbo (community-enhanced) versions instead of vanilla releases
# due to the sad fact that `-jumbo-???' suffixed versions *precede* official
# ones per pkg_version(1) -t check.  So, when Alexander rolls out new "plain"
# release, just hold the horses and wait for corresponding -jumbo one, which
# usually does not take too long to appear.
#
PORTSCOUT=	limit:.*-jumbo

OSNAME=		freebsd
CFLAGS+=	-DJOHN_SYSTEMWIDE=1 \
		-DJOHN_SYSTEMWIDE_HOME=\\"${DATADIR}\\" \
		-DCFG_FULL_NAME=\\"${PREFIX}/etc/${PORTNAME}.conf\\"

PORTDOCS=	CHANGES CONFIG EXAMPLES EXTERNAL FAQ MODES OPTIONS README \
		RULES CONTACT CREDITS

OPTIONS_DEFINE=	OPENMP DOCS
OPENMP_DESC=	Compile with OpenMP support
OPENMP_USES=	compiler:openmp

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
. if ${MACHINE_CPU:Msse2}
ALL_TARGET=	${OSNAME}-x86-sse2
. elif ${MACHINE_CPU:Mmmx}
ALL_TARGET=	${OSNAME}-x86-mmx
. else
ALL_TARGET=	${OSNAME}-x86-any
. endif
.elif ${ARCH} == "amd64"
ALL_TARGET=	${OSNAME}-x86-64
.else
ALL_TARGET=	generic
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
CFLAGS+=	-flax-vector-conversions
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|= gcc|= ${CC}|' \
		-e '/^CFLAGS =/s|-O2|${CFLAGS}|' ${WRKSRC}/src/Makefile
.if ${PORT_OPTIONS:MOPENMP}
	@${REINPLACE_CMD} -E \
		'/(fopenmp|-m${MACHINE_CPU:Msse2})$$/s,#(OMPFLAGS =),\1,' \
			${WRKSRC}/src/Makefile
.endif
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/run/*.rb
	@${REINPLACE_CMD} -e '/_XOPEN_SOURCE/d' ${WRKSRC}/src/recovery.c
# Replace methods and types that were marked deprecated by OpenSSL 0.9.7
# and will be removed in OpenSSL 1.1.0
	@${REINPLACE_CMD} -e 's|des_string_to_key|DES_string_to_key|' \
		${WRKSRC}/src/KRB4_fmt_plug.c
	@${REINPLACE_CMD} -e 's|des_set_odd_parity|DES_set_odd_parity|' \
		${WRKSRC}/src/KRB4_std_plug.c
	@${REINPLACE_CMD} -e 's|C_Block|DES_cblock|' \
		${WRKSRC}/src/keychain_fmt_plug.c

pre-build:
	@${ECHO_CMD}
	@${ECHO_CMD} "Building John the Ripper for ${ALL_TARGET}" \
		${WITH_OPENMP:C/.*/with/}${WITHOUT_OPENMP:C/.*/without/} \
		"OpenMP support"
	@${ECHO_CMD}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run/john ${STAGEDIR}${PREFIX}/bin
	${LN} -sf john ${STAGEDIR}${PREFIX}/bin/xtract
	${LN} -sf john ${STAGEDIR}${PREFIX}/bin/unshadow
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/run && ${INSTALL_DATA} *.??? [^j]*.conf ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/run && ${INSTALL_SCRIPT} *.?? mailer ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/run/john.conf \
		${STAGEDIR}${PREFIX}/etc/john.conf.default
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
