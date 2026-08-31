PORTNAME=	libgcrypt
DISTVERSION=	1.12.3
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	cy@FreeBSD.org
COMMENT=	General purpose cryptographic library based on the code from GnuPG
WWW=		https://www.gnupg.org/software/libgcrypt/index.html

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.32:security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.32:security/libgpg-error

USES=		cpe libtool pathfix tar:bzip2

CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CFLAGS+=	-pthread

TEST_TARGET=	check

DOCS=		AUTHORS ChangeLog ChangeLog-2011 INSTALL NEWS THANKS TODO \
		doc/HACKING doc/README.apichanges
PORTDOCS=	*

CONFIGURE_ARGS=	--disable-drng-support
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}

OPTIONS_DEFINE=		DOCS INFO STATIC AVX512
OPTIONS_DEFAULT=	DOCS INFO STATIC
OPTIONS_SUB=	yes

AVX512_DESC=		Include AVX512 support for FreeBSD 14 and 15

INFO_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-no-info
INFO_CONFIGURE_ENV=	MAKEINFO="${MAKEINFO} --no-split"
INFO_INFO=		gcrypt
INFO_USES=	makeinfo

STATIC_CONFIGURE_ENABLE=	static

.include <bsd.port.options.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
CONFIGURE_ARGS+=	--disable-jent-support
.endif

.if defined(WITH_DEBUG)
CFLAGS+=	-DWITH_DEBUG
.endif

.if (( ${OSVERSION} >= 1600000 && ${OSVERSION} < 1600017 ) || ( ${OSVERSION} >= 1500000 && ${OSVERSION} < 1501501 ) || ${OSVERSION} < 1404501 ) && ! ${PORT_OPTIONS:MAVX512}
# FreeBSD without llvm21 in base
CONFIGURE_ARGS+=--disable-avx512-support
.elif (( ${OSVERSION} >= 1600000 && ${OSVERSION} < 1600017 ) || ( ${OSVERSION} >= 1500000 && ${OSVERSION} < 1501501 ) || ${OSVERSION} < 1404501 ) && ${PORT_OPTIONS:MAVX512}
USES+=		llvm:min=20
# User wants AVX512 support anyway
.else
# FreeBSD with LLVM21 in base supports AVX512
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/gcrypt.info*
	@${REINPLACE_CMD} -e 's|ALIGN (3)|ALIGN (2)|g' ${WRKSRC}/mpi/i386/*.S

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
