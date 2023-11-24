PORTNAME=	libgcrypt
DISTVERSION=	1.10.3
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	cy@FreeBSD.org
COMMENT=	General purpose cryptographic library based on the code from GnuPG
WWW=		https://www.gnupg.org/software/libgcrypt/index.html

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	libgpg-error>=1.32:security/libgpg-error
RUN_DEPENDS=	libgpg-error>=1.32:security/libgpg-error

USES=		cpe libtool tar:bzip2

CPE_VENDOR=	gnupg
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-drng-support
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
USE_LDCONFIG=	yes
TEST_TARGET=	check

DOCS=		AUTHORS ChangeLog ChangeLog-2011 INSTALL NEWS THANKS TODO \
		doc/HACKING doc/README.apichanges
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS INFO STATIC
OPTIONS_DEFAULT=	DOCS INFO STATIC
OPTIONS_SUB=	yes

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

post-patch:
	@${RM} ${WRKSRC}/doc/gcrypt.info*
	@${REINPLACE_CMD} -e 's|ALIGN (3)|ALIGN (2)|g' ${WRKSRC}/mpi/i386/*.S

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
