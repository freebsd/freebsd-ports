# Created by: David O'Brien <obrien@FreeBSD.org>

PORTNAME=	john
# NB: starting from the next version, community-enhanced (jumbo) patch
# should be offered as an option (suggested by Solar Designer himself).
DISTVERSION=	1.9.0-jumbo-1
CATEGORIES=	security
MASTER_SITES=	http://www.openwall.com/john/j/ \
		http://mirrors.kernel.org/openwall/projects/john/${DISTVERSION:C/-.*//}/ \
		http://distro.ibiblio.org/openwall/projects/john/${DISTVERSION:C/-.*//}/
PATCH_STRIP=	-p2

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Featureful Unix password cracker

LICENSE=	GPLv2+

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake shebangfix ssl tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS_EXTRA="-DJOHN_SYSTEMWIDE=1" \
		OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
SHEBANG_FILES=	../run/*.pl ../run/*.rb ../run/benchmark-unify ../run/relbench
WRKSRC_SUBDIR=	src
ALL_TARGET=	default

BINARIES=	SIPdump bitlocker2john calc_stat cprepair dmg2john \
		eapmd5tojohn genmkvpwd hccap2john john keepass2john \
		mkvcalcproba putty2john racf2john raw2dyna tgtsnarf \
		uaf2john vncpcap2john wpapcap2john

BINLINKS=	base64conv gpg2john rar2john unafs undrop unique \
		unshadow zip2john

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS OPENCL OPENMP
OPTIONS_DEFAULT=	OPENMP
OPTIONS_SUB=	yes

OPENCL_BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:devel/opencl
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd
OPENCL_CONFIGURE_OFF=	--disable-opencl
OPENCL_USES=		perl5
OPENCL_USE=		PERL5=build

OPENMP_CONFIGURE_OFF=	--disable-openmp

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
CONFIGURE_ARGS+=	--disable-simd
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/params.h
	@${REINPLACE_CMD} -e '/^host_cpu=/s|$$| ; case $$host_cpu in\
		amd64) host_cpu=x86_64 ;; esac|' ${WRKSRC}/configure

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
	cd ${WRKSRC}/../run && ${INSTALL_DATA} *.?? *.lua benchmark-unify \
		dictionary.rfc2865 fuzz.dic john.*sh_completion mailer \
		makechr oui.txt relbench stats ${STAGEDIR}${DATADIR}/extra
	${CP} -a ${WRKSRC}/../run/rules ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/../run && ${CP} -a dns lib ztex \
		${STAGEDIR}${DATADIR}/extra
	@${RM} ${STAGEDIR}${DATADIR}/extra/dns/README.txt

do-install-OPENCL-on:
	${CP} -a ${WRKSRC}/../run/kernels ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MV} ${WRKSRC}/../doc/extras/* ${WRKSRC}/../*.md ${WRKSRC}/../doc
	@${RMDIR} ${WRKSRC}/../doc/extras
	@${RM} ${WRKSRC}/../doc/COPYING ${WRKSRC}/../doc/README
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

.if defined(PACKAGE_BUILDING) || defined(BATCH)
.  if ${ARCH} == amd64 || ${ARCH} == i386
CONFIGURE_ARGS+=	--enable-simd=sse2
.  endif
.endif
